#include "MainForm.h"
#include "ui_MainForm.h"
#include <QDesktopWidget>
#include "Component/PenManager.h"
#include "Form/SignForm.h"
MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    QDesktopWidget *desktop=QApplication::desktop();
    move((desktop->width()-width())/2,(desktop->height()-height())/2);
    ui->setupUi(this);
    PenManager* m = PEN_MANAGER;
    connect(m,&PenManager::OnPenConnected,[=](QString serial){
        ui->stackedWidget->setCurrentIndex(1);
        ui->label_PenSerial->setText(serial);
    });
    connect(m,&PenManager::OnPenDisconnect,[=]{
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_penMessage->setText("未连接智能笔！");
    });
    connect(ui->btn_Enter,&QPushButton::clicked,[]{
        SignForm::GetInstance()->show();
    });
    connect(m,&PenManager::OnColorChanged,[=](int penColor){
        QString color="black";
        switch (penColor) {
            case 0:color="black";break;
            case 1:color="red";break;
            case 2:color="blue";break;
            case 3:color="green";break;
        }
        ui->label_penColor->setStyleSheet("background-color:"+color+";border-radius:2px;");
    });
    connect(m,&PenManager::OnWidthChanged,[=](int penThickness){
        ui->label_penThickness->setText(QString::number(penThickness,10));
    }); 
    ui->stackedWidget->setCurrentIndex(0);
}

MainForm::~MainForm()
{
    delete ui;
}
