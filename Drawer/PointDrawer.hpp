#ifndef POINTDRAWER_HPP
#define POINTDRAWER_HPP
#include <QObject>
#include <Qt_Heads.h>
#include "Models/StrokeModel.hpp"

class PointDrawer:public QWidget
{
        Q_OBJECT
    public:
        explicit PointDrawer(QSize size,float scale,QWidget *parent = nullptr){
            this->Scale=scale;
            this->setParent(parent);
            this->resize(size);
            this->show();
        }
        void DrawStroke(StrokeModel* strokeModel){
            currentStroke=strokeModel;
            this->repaint();
        }
        ~PointDrawer(){}
    protected:
        void paintEvent(QPaintEvent *e)override
        {
            if(this->currentStroke!=nullptr)
            {
                QPainter strokep(this);
                strokep.setRenderHint(QPainter::Antialiasing,true);
                strokep.scale(Scale,Scale);
                strokep.setPen(CreatePen(this->currentStroke->c,this->currentStroke->t));

                int pointsize = this->currentStroke->pointList->size();
                if(pointsize>0){
                    StrokePointModel fitstPoint = this->currentStroke->pointList->at(0);

                    QPainterPath p;
                    p.moveTo(  QPointF(fitstPoint.x,fitstPoint.y));

                    for(int k = 1;k < pointsize;k++)
                    {
                        QPointF  drawlast = QPointF(this->currentStroke->pointList->at(k-1).x,this->currentStroke->pointList->at(k-1).y);

                        QPointF drawcurr = QPointF(this->currentStroke->pointList->at(k).x,this->currentStroke->pointList->at(k).y);

                        float offsetX = ((float)(drawcurr.x() - drawlast.x()) );
                        float offsetY = ((float)(drawcurr.y() - drawlast.y()) );

                        float fin = sqrt(offsetX * offsetX + offsetY * offsetY);


                        if(fin>=2){
                            QPointF control = QPointF(drawlast.x()+offsetX/3.0,
                                                      drawlast.y()+offsetY/3.0);
                            QPointF end = QPointF(drawlast.x()+offsetX/3.0*2.0,
                                                  drawlast.y()+offsetY/3.0*2.0);
                            p.cubicTo(drawlast,control,end);

                        }
                        else if(fin>=1)
                        {
                            QPointF control = QPointF(drawlast.x()+offsetX/2.0,
                                                      drawlast.y()+offsetY/2.0);
                            p.quadTo(drawlast,control);

                        }
                        else{
                            p.lineTo(drawcurr);
                        }

                    }
                    strokep.drawPath(p);
                }
            }
            e->accept();
        }
    private:
        float Scale = 1;
        StrokeModel *currentStroke=nullptr;
};
#endif // POINTDRAWER_HPP
