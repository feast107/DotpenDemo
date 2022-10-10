#include "Form/SignForm.h"
#include <QApplication>
#include <QtTool_global.h>
#include "Form/MainForm.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm s;
    s.show();
    return a.exec();
}
