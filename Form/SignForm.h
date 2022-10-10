#ifndef SIGNFORM_H
#define SIGNFORM_H

#include <pch.h>
#include <QWidget>
#include <QShowEvent>
#include <Drawer/StrokeDrawer.h>
#include <QVBoxLayout>
namespace Ui {
    class SignForm;
}

class SignForm : public QWidget
{
        friend class FileManager;
        Q_OBJECT
    public:
        static SignForm* GetInstance();
        ~SignForm();
    public slots:
        void PenConnectEvent(QString penSerial);
        void PenDisconnectEvent();

        void PenThicknessChangeEvent(int penThickness);
        void PenColorChangeEvent(int penColor);

        void PenUpEvent();
        void PenMoveEvent(QString pageAddress, QPoint dotPoint);
        void PenDownEvent();

        void StoreEvent();
        void ClearEvent();
        void ResetEvent();
    protected:
        void showEvent(QShowEvent* event)override;
        void closeEvent(QCloseEvent *event)override;
    private:
        explicit SignForm(QWidget *parent = 0);
        static SignForm* instance ;

        class Page{
            public:
                static QPixmap* sharedPicture;

                bool isGetPoint=false;
                bool isPenDown=false;
                QList<StrokeModel*>* strokeList;
                StrokeModel *currentStroke;
                File file;
                int storedIndex;

                QPixmap* initialPic = NULL;
                QPixmap* currPic = NULL;
                QLabel* label;
                QSize size;
                Page(File f,QList<StrokeModel*>* strokes,const QSize & size):size(size),file(f),storedIndex(strokes->length()){
                    if(sharedPicture == NULL){
                        sharedPicture = new QPixmap();
                        sharedPicture->load(":Resource/Image/boardsign.png");
                        *sharedPicture = sharedPicture->scaled(size);
                    }
                    initialPic = GetInitialPage();
                    strokeList = strokes;
                }
                ~Page(){
                    delete strokeList;
                    if(initialPic!=NULL){
                        delete initialPic;
                    }
                    if(currPic!=NULL){
                        delete currPic;
                    }
                }
                void Finalize();
                void SetThumbnail(QPixmap *pic);
                QPixmap* GetInitialPage(){
                    QPixmap* ret = new QPixmap(sharedPicture->copy());
                    return ret;
                }
        };
        int CachedWidth = 0;
        QMap<int,Page*> pages;
        Page* currentPage = NULL;
        Ui::SignForm *ui;
        StrokeDrawer* strokeDrawer = NULL;
        int PageMaximun = 0;
        QVBoxLayout * layout = NULL;
        QSpacerItem* spacer = NULL;
        void AttachEvents();
        void DetachEvents();
        void InitPages();
        void AddPage();
        QPushButton* CreateButton(int index,Page * page);
        void Switch(Page* page);
        void Remove(int index,Page* page);
        void ResizeAllButton(int NewWidth);
        Page* CurrentPage()const;

};

#endif // SIGNFORM_H
