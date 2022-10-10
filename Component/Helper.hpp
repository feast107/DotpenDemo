#ifndef HELPER_H
#define HELPER_H
#include <Qt_Heads.h>
#include "Include/TQLComm.h"
#include "PenManager.h"
#include "Models/StrokePointModel.hpp"

inline int About(float num)
{
    int ret = (int)num;
    if( (num-(float)ret)>=0.5f){
        ret += 1;
    }
    return ret;
}

/**
 * @brief GLDrawer::D2P 转化点
 * @param dot
 * @return
 */
inline QPoint Dot2Point(Dot* dot)
{
    return QPoint((dot->x*100 + dot->fx),(dot->y*100 + dot->fy));
}

inline QPointF Dot2PointF(Dot* dot)
{
    return QPointF((dot->x + dot->fx/100.0),(dot->y + dot->fy/100.0));
}


inline bool InsideOf(QRect region,QPoint point){
    if(region.left() <= point.x() && region.right() >= point.x() &&
       region.top() <= point.y() && region.bottom() >= point.y()){
        return true;
    }else{
        return false;
    }
}

inline bool InsideOf(QRectF region,QPoint point){
    if(region.left() <= (float)point.x() && region.right() >= (float)point.x() &&
       region.top() <= (float)point.y() && region.bottom() >= (float)point.y()){
        return true;
    }else{
        return false;
    }
}

inline QPen CreatePen(int color,int width,int transparent = 255){
    QPen ret(QColor(0,0,0),1,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    switch((PenManager::PenColor)color)
    {
        case PenManager::BLACK:
        {
            ret.setColor(QColor(0,0,0,transparent));
            break;
        }
        case PenManager::BLUE:
        {
            ret.setColor(QColor(0,0,255,transparent));
            break;
        }
        case PenManager::RED:
        {
            ret.setColor(QColor(255,0,0,transparent));
            break;
        }
        case PenManager::GREEN:
        {
            ret.setColor(QColor(0,80,0,transparent));
            break;
        }
    }
    switch((PenManager::PenWidth)width)
    {
        case PenManager::ONE:
        {
            ret.setWidthF(10);
            break;
        }
        case PenManager::TWO:
        {
            ret.setWidthF(20);
            break;
        }
        case PenManager::THREE:
        {
            ret.setWidthF(30);
            break;
        }
        case PenManager::FOUR:
        {
            ret.setWidthF(40);
            break;
        }
        case PenManager::FIVE:
        {
            ret.setWidthF(50);
            break;
        }
    }
    return ret;
}

inline QPainter* InitPainter(QPaintDevice *image){
    QPainter* p = new QPainter(image);
    QColor white("#FFFFFF");
    white.setAlpha(0);
    p->setBrush(QBrush(white));
    p->setRenderHints( QPainter::SmoothPixmapTransform, true);
    return p;
}

inline QString SerializeStroke(QList<StrokePointModel>* points)
{
    if (points == NULL || points->size() == 0)
    {
        return "";
    }
    int j = 0;

    int oldX;
    int oldY;
    int curX;
    int curY;
    QString ret = "";
    StrokePointModel point;
    if (points->size() > 0)
    {
        point = points->at(0);
        //第一个点为M起点
        ret += (QString("M") + QString::number(point.x,10) + QString(" ") +
                QString::number(point.y,10) + QString("l"));
        oldX = point.x;
        oldY = point.y;

        if (points->size() > 1)
        {
            j = 1;
            //L第一个点特殊处理
            point = points->at(j);
            curX = (point.x - oldX);
            curY = (point.y - oldY);
            oldX = point.x;
            oldY = point.y;
            ret.append(QString::number(curX,10));
            if (curY >= 0)
            {
                ret += " ";
            }
            ret.append(QString::number(curY,10));
            j++;

            while (j < points->size())
            {
                point = points->at(j);
                curX = (point.x - oldX);
                curY = (point.y - oldY);
                oldX = point.x;
                oldY = point.y;
                if (curX == 0 && curY == 0)
                {
                    j++;
                    continue;
                }

                if (curX >= 0)
                {
                    ret.append(" ");
                }
                ret.append(QString::number(curX,10));

                if (curY >= 0)
                {
                    ret.append(" ");
                }
                ret.append(QString::number(curY,10));
                j++;
            }
        }
    }
    return ret;
}
#define SERIALIZESTROKE SerializeStroke

inline QList<StrokePointModel>* DeSerializeStroke(QString svgPointsPath)
{
    QList<StrokePointModel>* points=new  QList<StrokePointModel>() ;
    if ("" != svgPointsPath)
    {
        QStringList dataArray = svgPointsPath.split('l');
        int firstPointX, firstPointY;
        if (dataArray.size() == 2)
        {
            try
            {
                QString tmp = dataArray.at(0);
                QStringList firstPontArray = tmp.replace("M", "").split(' ');
                tmp = firstPontArray[0];
                firstPointX = tmp.trimmed().toInt();
                tmp = firstPontArray[1];
                firstPointY = tmp.trimmed().toInt();
                points->append(StrokePointModel(firstPointX, firstPointY));
                tmp = dataArray.at(1);
                QStringList pointsArray = tmp.replace("l", "")
                                          .replace("-", " -")
                                          .trimmed()
                                          .split(' ');
                for (int i = 0; i < pointsArray.size(); i=i+2)
                {
                    try
                    {
                        if (i + 1 < pointsArray.size())
                        {
                            tmp = pointsArray.at(i);
                            firstPointX = firstPointX + tmp.trimmed().toInt();
                            tmp = pointsArray.at(i+1);
                            firstPointY = firstPointY + tmp.trimmed().toInt();
                            points->append(StrokePointModel(firstPointX, firstPointY));
                        }
                    }
                    catch(std::exception &e){
                        qDebug()<<e.what();
                    }              
                }
            }
            catch(std::exception &e){
                qDebug()<<e.what();
            }
        }
    }
    return points;
}


inline void ScaleSize(QSize* size,float scale){
    size->setHeight(size->height()*scale);
    size->setWidth(size->width()*scale);
}

inline void ScaleRect(QRect* rect,float scale){
    rect->setBottom(rect->bottom()*scale);
    rect->setRight(rect->right()*scale);
    rect->setLeft(rect->left()*scale);
    rect->setTop(rect->top()*scale);
}

inline void ScaleRectF(QRectF* rect,float scale){
    rect->setBottom(rect->bottom()*scale);
    rect->setRight(rect->right()*scale);
    rect->setLeft(rect->left()*scale);
    rect->setTop(rect->top()*scale);
}

inline QString ToBase64(QPixmap* img){
    QByteArray ba;
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    img->save(&buf, "PNG");
    QByteArray ba2 = ba.toBase64();
    return QString::fromLatin1(ba2);
}

inline QPixmap FromBase64(QString base64){
    base64 = base64.replace(0,QString(STRING_JSON_BASE64HEAD).length(),"");
    QByteArray arr = QByteArray::fromBase64(base64.toLatin1());
    QPixmap pic;
    pic.loadFromData(arr);
    return pic;
}

inline void AnalyzeLink(QString m,QString* p1,QString* p2,QString* p3)
{
    QString tmp;
    int b = 0;
    for(int i = 0 ; i<m.length();i++){
        switch(b)
        {
            case 0:
            {
                if(i>3 && m.at(i)=='/' && m.at(i-1)=='/'){
                    b++;
                }
                break;
            }
            case 1:
            {
                if(m.at(i)==','){
                    b++;
                    *p1 = tmp;
                    tmp="";
                }else{
                    tmp+=m.at(i);
                }
                break;
            }
            case 2:
            {
                if(m.at(i)==','){
                    b++;
                    *p2 = tmp;
                    tmp="";
                }else{
                    tmp+=m.at(i);
                }
                break;
            }
            case 3:
            {
                tmp+=m.at(i);
                break;
            }
        }
    }
    *p3 = tmp;
}


inline QList<int> AnalyzeAddress(QString Address){
    QList<int> ret;
    QString tmp = "";
    for(int i = 0;i<Address.length();i++){
        QChar c = Address.at(i);
        if(c !='.'){
            tmp+=c;
        }else{
            ret.push_back(tmp.toInt());
            tmp = "";
        }
    }
    ret.push_back(tmp.toInt());
    return ret;
}

inline QList<int> AddressToList(int SectionId,int OwnerId,int NoteId,int PageId){
    QList<int> ret;
    ret.push_back(SectionId);
    ret.push_back(OwnerId);
    ret.push_back(NoteId);
    ret.push_back(PageId);
    return ret;
}

inline QList<int> GetDotAddress(Dot* dot)
{
    return AddressToList(dot->sectionId,dot->ownerId,dot->noteId,dot->pageId);
}

inline QString GenerateAddress(int SectionId,int OwnerId,int NoteId,int PageId){
    return QString::number(SectionId)+'.'+QString::number(OwnerId)+'.'+
            QString::number(NoteId)+'.'+QString::number(PageId);
}

inline QString GenerateAddress(QList<int> address){
    return GenerateAddress(address[0],address[1],address[2],address[3]);
}

inline bool ValidAddress(int SectionId,int OwnerId,int NoteId,int PageId){
    if(SectionId != 0 ||OwnerId != 3 ||NoteId > 15 ||NoteId < 0 ||PageId < 0 || PageId > 255){
        return false;
    }else{
        return true;
    }
}

inline bool ValidAddress(QList<int> address){
    return ValidAddress(address[0],address[1],address[2],address[3]);
}

#endif // HELPER_H
