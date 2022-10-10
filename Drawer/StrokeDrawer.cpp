#include "StrokeDrawer.h"
#include "Component/Helper.hpp"
#include "math.h"

StrokeDrawer::StrokeDrawer(QSize size, float scale, QWidget *parent) : QWidget(parent)
{
    this->Scale=scale;
    this->setParent(parent);
    this->resize(size);
    this->show();

    pointDrawer=new PointDrawer(size,scale,this);

}

void StrokeDrawer::SetTransparent(int Transparent)
{
    transparent=Transparent;
}


void StrokeDrawer::BindStrokeList(QList<StrokeModel *> *strokes)
{
    this->strokeList=strokes;
}

void StrokeDrawer::DrawStrokeList()
{
    DrawStroke(nullptr);
    this->repaint();
}

QPixmap StrokeDrawer::ExportArea(QRect area)
{
    QPixmap* map = new QPixmap(this->size());
    map->fill(Qt::transparent);
    DrawFunction(map,Scale);
    ScaleRect(&area,Scale);
    return map->copy(area);
}

QPixmap* StrokeDrawer::Export()
{
    QPixmap* map = new QPixmap(this->size());
    map->fill(Qt::transparent);
    DrawFunction(map,Scale);
    return map;
}

QPixmap* StrokeDrawer::Export(QPixmap *background)
{
    DrawFunction(background,Scale);
    return background;
}


void StrokeDrawer::DrawStroke(StrokeModel* stroke)
{
    pointDrawer->DrawStroke(stroke);
}

void StrokeDrawer::SetBackPic(QPixmap *pic)
{
    if(backLayer!=NULL){
        delete backLayer;
        backLayer = NULL;
    }
    backLayer = pic;
}

void StrokeDrawer::paintEvent(QPaintEvent *e)
{
    if(backLayer != NULL){
        QPainter backP(this);
        backP.drawPixmap(QPoint(0,0),backLayer->scaled(this->size(),
                                                       Qt::IgnoreAspectRatio,
                                                       Qt::SmoothTransformation));
    }
    if(strokeList!=NULL && strokeList->size()>0)
    {
        DrawFunction(this,Scale);
    }
}

void StrokeDrawer::DrawFunction(QPaintDevice *device,float Scale)
{
    if(strokeList!=NULL){
        int strokeSize=strokeList->size();
        QPainter strokep(device);
        strokep.setRenderHint(QPainter::HighQualityAntialiasing,true);
        strokep.scale(Scale,Scale);
        for(int i = 0;i<strokeSize;i++){
            StrokeModel* model = strokeList->at(i);
            strokep.setPen(CreatePen(model->c,model->t,transparent));
            int pointsize = model->pointList->size();
            if(pointsize>0){
                StrokePointModel firstPoint = model->pointList->at(0);
                QPainterPath qpath;
                qpath.moveTo( QPointF(firstPoint.x,firstPoint.y));
                for(int k = 1;k < pointsize;k++)
                {
                    QPointF drawlast = QPointF(model->pointList->at(k-1).x,
                                               model->pointList->at(k-1).y);
                    QPointF drawcurr = QPointF(model->pointList->at(k).x,
                                               model->pointList->at(k).y);
                    float offsetX = ((float)(drawcurr.x() - drawlast.x()));
                    float offsetY = ((float)(drawcurr.y() - drawlast.y()));
                    float fin = sqrt(offsetX * offsetX + offsetY * offsetY);
                    if(fin>=2){
                        QPointF control = QPointF(drawlast.x()+offsetX/3.0,
                                                  drawlast.y()+offsetY/3.0);
                        QPointF end = QPointF(drawlast.x()+offsetX/3.0*2.0,
                                              drawlast.y()+offsetY/3.0*2.0);
                        qpath.cubicTo(drawlast,control,end);
                    }
                    else if(fin>=1)
                    {
                        QPointF control = QPointF(drawlast.x()+offsetX/2.0,
                                                  drawlast.y()+offsetY/2.0);
                        qpath.quadTo(drawlast,control);
                    }
                    else{
                        qpath.lineTo(drawcurr);
                    }
                }
                strokep.drawPath(qpath);
            }
        }
    }
}

