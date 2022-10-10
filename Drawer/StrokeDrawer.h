#ifndef SIGNDRAWER_H
#define SIGNDRAWER_H

#include <QObject>
#include <Qt_Heads.h>
#include "Models/StrokeModel.hpp"
#include "PointDrawer.hpp"
class StrokeDrawer : public QWidget
{
        Q_OBJECT
    private :
        QPixmap* backLayer =NULL;
        float ZOOM  = 1;
        float Scale = 1;
        int transparent = 255;
    public:
        explicit StrokeDrawer(QSize size,float scale, QWidget *parent = nullptr);
        void SetTransparent(int Transparent);
        void SetBackPic(QPixmap* pic);
        void BindStrokeList(QList<StrokeModel*>* strokes);

        void DrawStrokeList();
        QPixmap ExportArea(QRect area);
        QPixmap *Export();
        QPixmap *Export(QPixmap* background);
        void DrawStroke(StrokeModel* strokeModel);
        ~StrokeDrawer(){
            delete pointDrawer;
        }
    protected:
        void paintEvent(QPaintEvent *e)override;

    private:
        QList<StrokeModel*> *strokeList = NULL;
        PointDrawer *pointDrawer;
        void DrawFunction(QPaintDevice* device,float scale);
    signals:
    public slots:
};

#endif // SIGNDRAWER_H
