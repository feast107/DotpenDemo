#include "SignForm.h"
#include "ui_SignForm.h"
#include <QDesktopWidget>
#include <Component/PenManager.h>
#include <Component/FileManager.h>
#include <QBoxLayout>

SignForm* SignForm::instance = NULL;
QPixmap* SignForm::Page::sharedPicture = NULL;
SignForm::SignForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignForm)
{
    setAttribute(Qt::WA_DeleteOnClose);
    QDesktopWidget *desktop=QApplication::desktop();
    setFixedSize(100,desktop->height()-180);
    move((desktop->width()-width())/2,180/ 2);
    setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);

    PenManager* m = PEN_MANAGER;
    connect(m,&PenManager::OnPenConnected ,this,&SignForm::PenConnectEvent);
    connect(m,&PenManager::OnPenDisconnect,this,&SignForm::PenDisconnectEvent);

    ui->setupUi(this);

    connect(ui->btn_reset,  &QPushButton::clicked,this,&SignForm::ResetEvent);
    connect(ui->btn_clear,  &QPushButton::clicked,this,&SignForm::ClearEvent);
    connect(ui->btn_addPage,&QPushButton::clicked,this,&SignForm::AddPage);

}

SignForm *SignForm::GetInstance()
{
    if(instance == NULL){
        instance = new SignForm();
    }
    return instance;
}

SignForm::~SignForm()
{
    delete ui;
    strokeDrawer->BindStrokeList(NULL);
    delete strokeDrawer;
    for(auto page :this->pages){
        delete page;
    }
    delete layout;
    instance = NULL;
    if(Page::sharedPicture!=NULL){
        delete Page::sharedPicture;
        Page::sharedPicture = NULL;
    }
}

void SignForm::showEvent(QShowEvent *event)
{
    QDesktopWidget *desktop=QApplication::desktop();
    int windowWidth= ui->formPic->height() / 264.0 * 193.0 + 175;
    setFixedSize(windowWidth,desktop->height()-180);
    move((desktop->width()-width())/2 , 180/ 2);

    strokeDrawer = new StrokeDrawer(ui->formPic->size(),
                                    (float)(this->ui->formPic->width()/(float)( 193.0 * 80.0 / 3.0)),
                                    this->ui->formPic);
    InitPages();

    if(pages.count()>0){
        Switch(pages.first());
    }
    event->accept();
    if(PEN_MANAGER->IsConnected()){
        PenConnectEvent(        PEN_MANAGER->GetPenSerial());
        PenColorChangeEvent(    PEN_MANAGER->GetCurrentPenColor());
        PenThicknessChangeEvent(PEN_MANAGER->GetCurrentPenWidth());
    }
}

void SignForm::closeEvent(QCloseEvent *event)
{
    strokeDrawer->DrawStrokeList();
    auto P = CurrentPage();
    if( P != NULL){
        P->Finalize();
    }
    StoreEvent();
    event->accept();
}

/**
 * @brief 连接笔事件
 */
void SignForm::AttachEvents()
{
    PenManager* m = PEN_MANAGER;

    connect(m,&PenManager::OnColorChanged, this,&SignForm::PenColorChangeEvent);
    connect(m,&PenManager::OnWidthChanged, this,&SignForm::PenThicknessChangeEvent);
    connect(m,&PenManager::OnPenMove,      this,&SignForm::PenMoveEvent);
    connect(m,&PenManager::OnPenUp,        this,&SignForm::PenUpEvent);
    connect(m,&PenManager::OnPenDown,      this,&SignForm::PenDownEvent);
    connect(m,&PenManager::OnClear,        this,&SignForm::ClearEvent);
}

/**
 * @brief 解除笔事件
 */
void SignForm::DetachEvents()
{
    PenManager* m = PEN_MANAGER;

    disconnect(m,&PenManager::OnColorChanged, this,&SignForm::PenColorChangeEvent);
    disconnect(m,&PenManager::OnWidthChanged, this,&SignForm::PenThicknessChangeEvent);
    disconnect(m,&PenManager::OnPenMove,      this,&SignForm::PenMoveEvent);
    disconnect(m,&PenManager::OnPenUp,        this,&SignForm::PenUpEvent);
    disconnect(m,&PenManager::OnPenDown,      this,&SignForm::PenDownEvent);
    disconnect(m,&PenManager::OnClear,        this,&SignForm::ClearEvent);
}

/**
 * @brief 初始化页面
 */
void SignForm::InitPages()
{
    QList<File> fs = FileManager::GetFiles();
    PageMaximun = fs.length();
    QWidget* pList = ui->page_List;
    layout = (QVBoxLayout*)pList->layout();
    if(layout==NULL){
        layout = new QVBoxLayout();
        pList->setLayout(layout);
        int i = 1 ;
        for(auto f:fs){
            QList<StrokeModel *> * strokes = FileManager::Load(f);
            Page* p = new Page(f,strokes,ui->formPic->size());
            pages.insert(i,p);
            layout->addWidget(CreateButton(i++,p));
            strokeDrawer->BindStrokeList(p->strokeList);
            p->SetThumbnail(strokeDrawer->Export(p->GetInitialPage()));
        }
        spacer = new QSpacerItem(1,pList->height(),
                                 QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);
        layout->addSpacerItem(spacer);
    }

}

/**
 * @brief SignForm::AddPage
 */
void SignForm::AddPage()
{
    PageMaximun++ ;
    if(!pages.contains(PageMaximun)){
        Page* p = new Page(FileManager::Add(),new QList<StrokeModel*>(),ui->formPic->size());
        pages.insert(PageMaximun,p);
        ui->page_List->layout()->removeItem(spacer);
        ui->page_List->layout()->addWidget(CreateButton(PageMaximun,p));
        ui->page_List->layout()->addItem(spacer);
        Switch(p);
    }
}

/**
 * @brief SignForm::CreateButton
 * @param index
 * @param page
 * @return
 */
QPushButton* SignForm::CreateButton(int index,Page *page)
{
    QPushButton *item = new QPushButton();
    //item->setText(QString::number(index,10) + QString("页"));
    int width = ui->page_List->width()-ui->page_List->layout()->contentsMargins().right()*2;
    item->setObjectName("PageButton");

    item->setFixedSize(QSize(104,(float)104/210.0*297.0));   //width height
    item->setStyleSheet("QPushButton:hover  { image:url(:Resource/Icon/delete.svg); }"
                        "QPushButton:focus  { outline:none; }");

    QLabel* l = new QLabel(item);
    page->label = l;
    l->setFixedSize(item->size().width()-4,item->size().height()-4);
    l->move(2,2);
    l->setPixmap(page->initialPic->scaled(l->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    l->setAutoFillBackground(true);
    QPushButton *closer = new QPushButton(item);
    closer->setFixedSize(QSize(20,20));
    closer->move(item->width()-closer->width() -5 ,5);
    closer->setStyleSheet("QPushButton        { border:none;  }"
                          "QPushButton:focus  { outline:none; }"
                          "QPushButton:pressed{ image:url(:Resource/Icon/delete-pressed.svg); }");
    connect(item,&QPushButton::clicked,[=]{
        Switch(page);
    });
    connect(closer,&QPushButton::clicked,[=]{
        ui->page_List->layout()->removeWidget(item);
        Remove(index,page);
        delete item;
    });
    return item;
}

void SignForm::Switch(SignForm::Page *page)
{
    auto P = CurrentPage();
    if(page != P && P!=NULL){
        P->Finalize();
        strokeDrawer->BindStrokeList(NULL);
    }
    currentPage = page;
    strokeDrawer->BindStrokeList(page->strokeList);
    strokeDrawer->DrawStrokeList();
    page->SetThumbnail(strokeDrawer->Export(page->GetInitialPage()));
}

void SignForm::Remove(int index, SignForm::Page *page)
{
    if(pages.contains(index)){
        pages.remove(index);
    }
    if(index == PageMaximun){
        PageMaximun --;
        while( (!pages.contains(PageMaximun)) && PageMaximun > 0 ){
            PageMaximun--;
        }
    }
    if(CurrentPage() == page){
        strokeDrawer->BindStrokeList(NULL);
        if(!pages.isEmpty()){
            bool find = false;
            int i = index - 1;
            while(!find){
                if(i > 0 && i < index ){
                    //向前查找
                    if(pages.contains(i)){
                        find = true;
                        Switch(pages.value(i));
                        break;
                    }
                    i--;
                }else if(i == 0){
                    i = index;
                }else
                {
                    //向后查找
                    if(pages.contains(i))
                    {
                        find = true;
                        Switch(pages.value(i));
                        break;
                    }
                    i++;
                }
            }
        }else
        {
            page->Finalize();
            currentPage = NULL;
            strokeDrawer->BindStrokeList(NULL);
            strokeDrawer->repaint();
        }
    }
    FileManager::Delete(page->file);
    delete page;
}

void SignForm::ResizeAllButton(int NewWidth)
{
    if(CachedWidth!=0){
        auto a = ui->page_List->children();
        for(auto b:a){
            if(b->objectName()=="PageButton"){
                ((QPushButton*)b)->setFixedSize(NewWidth,NewWidth/210.0*297.0);
            }
        }
    }
    CachedWidth = NewWidth;
}


SignForm::Page *SignForm::CurrentPage() const
{
    return currentPage;
}


void SignForm::PenColorChangeEvent(int penColor)
{
    QString color="black";
    switch (penColor) {
        case 0:color="black";break;
        case 1:color="red";break;
        case 2:color="blue";break;
        case 3:color="green";break;
    }
    ui->label_penColor->setStyleSheet("background-color:"+color+";border-radius:2px;");


}

void SignForm::PenThicknessChangeEvent(int penThickness)
{
    ui->label_penThickness->setText(QString::number(penThickness,10));
}

/**
 * @brief SignForm::PenConnectEvent
 * @param penSerial
 */
void SignForm::PenConnectEvent(QString penSerial){
    ui->label_penStatus->setText("已连接");
    ui->label_penStatus->setStyleSheet("color:green;");
    AttachEvents();
}

/**
 * @brief SignForm::PenDisconnectEvent
 */
void SignForm::PenDisconnectEvent(){
    ui->label_penStatus->setText("未连接");
    ui->label_penStatus->setStyleSheet("color:red;");
    DetachEvents();
}

/**
 * @brief SignForm::ClearEvent
 */
void SignForm::ClearEvent()
{
    auto P = CurrentPage();
    if(P!=NULL)
    {
        P->Finalize();
        strokeDrawer->DrawStrokeList();
        while(P->storedIndex<P->strokeList->length()){
            StrokeModel* stroke = P->strokeList->last();
            P->strokeList->removeLast();
            delete stroke;
        }
        strokeDrawer->repaint();
        P->SetThumbnail(strokeDrawer->Export(P->GetInitialPage()));
    }
}

void SignForm::ResetEvent()
{
    auto P = CurrentPage();
    if(P!=NULL){
        P->Finalize();

        strokeDrawer->DrawStrokeList();
        FileManager::Clean(P->file);
        P->storedIndex = 0;
        for(auto stroke: *P->strokeList){
            delete stroke;
        }
        P->strokeList->clear();
        strokeDrawer->repaint();
        P->SetThumbnail(P->initialPic);
    }
}

void SignForm::StoreEvent()
{
    for(auto page:pages){
        FileManager::Store(page);
    }
}

void SignForm::PenDownEvent()
{
    auto P =  CurrentPage();
    if(P!=NULL){
        P->isPenDown=true;
        P->isGetPoint=false;
    }
}

void SignForm::PenUpEvent()
{
    auto P = CurrentPage();
    if(P!=NULL){
        P->Finalize();
        strokeDrawer->DrawStrokeList();
        P->SetThumbnail(strokeDrawer->Export(P->GetInitialPage()));
    }
}

void SignForm::PenMoveEvent(QString pageAddress,QPoint dotPoint)
{
    auto P = CurrentPage();
    if(P!=NULL)
    {
        if(this->isHidden()||this->isMinimized() || !this->isActiveWindow()){
            this->activateWindow();
        }
        if(P->isPenDown)
        {
            if(P->isGetPoint==false)
            {
                P->currentStroke = new StrokeModel();
                P->currentStroke->c=PEN_MANAGER->GetCurrentPenColor();
                P->currentStroke->t=PEN_MANAGER->GetCurrentPenWidth();
                P->currentStroke->n=1;
                P->isGetPoint=true;
            }
            P->currentStroke->pointList->append(StrokePointModel(dotPoint.x(),dotPoint.y()));
            strokeDrawer->DrawStroke(P->currentStroke);
        }
    }
}

void SignForm::Page::Finalize()
{
    isPenDown = false;
    if(isGetPoint){
        strokeList->append(currentStroke);
        isGetPoint = false;
    }
}

void SignForm::Page::SetThumbnail(QPixmap *pic)
{
    if(pic!=NULL){
        delete currPic;
        currPic = NULL;
    }
    currPic = pic;
    label->setPixmap(pic->scaled(label->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
