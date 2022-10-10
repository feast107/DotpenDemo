#include "PenManager.h"
#include "TQLCallBack.h"
#include "Helper.hpp"

PenManager* PenManager::instance = NULL;

PenManager::PenManager(): QObject(nullptr)
{
    QRectF black( 14.584, 238.397, 10.628, 10.628);
    QRectF red( 27.2, 238.397, 10.628, 10.628);
    QRectF blue( 39.984, 238.397, 10.628, 10.628);
    QRectF green( 52.78, 238.397, 10.628, 10.628);
    QRectF thin( 65.57, 238.397, 10.628, 10.628);
    QRectF bold( 78.354, 238.397, 10.628, 10.628);
    QRectF clear(117.22, 238.397, 19.861, 10.448);
    QRectF cancel(143.032, 238.397, 17.287, 10.448);
    QRectF submit( 160.319, 238.397, 17.554, 10.448);

    ScaleRectF(&black,scale);
    ScaleRectF(&red,scale);
    ScaleRectF(&blue,scale);
    ScaleRectF(&green,scale);
    ScaleRectF(&thin,scale);
    ScaleRectF(&bold,scale);
    ScaleRectF(&clear,scale);
    ScaleRectF(&submit,scale);
    ScaleRectF(&cancel,scale);

    ColorAreas.insert(PenColor::BLACK,black);
    ColorAreas.insert(PenColor::RED,red);
    ColorAreas.insert(PenColor::BLUE,blue);
    ColorAreas.insert(PenColor::GREEN,green);
    WidthAreas.insert(PenWidthChange::THIN,thin);
    WidthAreas.insert(PenWidthChange::BOLD,bold);
    ClearArea = clear;
    CancelArea = cancel;
    SubmitArea = submit;
    InitCallBack();

}


void PenManager::SetPenSerial(QString penSerial)
{
    PenSerial = penSerial;
}

bool PenManager::IsConnected()
{
    return PenSerial!="";
}

void PenManager::OnPenConnect(QString penSerial)
{
    SetPenSerial(penSerial);
    emit OnPenConnected(penSerial);
    ConnectEvent(PenSerial);
}

void PenManager::OnPenDisConnect()
{
    PenSerial = "";
    PenHandle = NULL;
    emit OnPenDisconnect();
    DisConnectEvent();
}

void PenManager::OnNewDot(Dot *dot)
{
    QString pageaddress = GenerateAddress(GetDotAddress(dot));
    QPointF point = Dot2PointF(dot);
    QPoint dotPoint(qRound( point.x()*TransDot),qRound( point.y()*TransDot));
    switch(dot->type){
        case DotType::PEN_DOWN:
        {
            IsPenDown = true;
            //Process = true;
            emit OnPenDown();
            PenDownEvent();
            dot->type=DotType::PEN_MOVE;
            OnNewDot(dot);
            break;
        }
        case DotType::PEN_MOVE:
        {
            if(lastpoint.x()==dotPoint.x()&&lastpoint.y()==dotPoint.y()){
                return;
            }else{
                lastpoint = dotPoint;
            }
            //控件事件管线
            if(IsPenDown && Process){
                //提交事件
                if(pageaddress == "0.3.0.0")
                {
                    //提交
                    if(InsideOf(SubmitArea,dotPoint))
                    {
                        Process = false;
                        emit OnSubmit();
                        SubmitEvent();
                        return ;
                    }
                    //清空
                    if(InsideOf(ClearArea,dotPoint)){
                        Process = false;
                        emit OnClear();
                        ClearEvent();
                        return ;
                    }
                    //取消
                    if(InsideOf(CancelArea,dotPoint)){
                        Process = false;
                        emit OnCancel();
                        CancelEvent();
                        return ;
                    }
                    //颜色更变
                    auto iter = ColorAreas.begin();
                    while(iter != ColorAreas.end())
                    {
                        if(InsideOf(iter.value(),dotPoint))
                        {
                            Process = false;
                            tmpcolor = iter.key();
                            emit OnColorChanged(tmpcolor);
                            ColorChangedEvent(tmpcolor);
                            return ;
                        }
                        iter++;
                    }
                    //粗细更变
                    auto iter2 = WidthAreas.begin();
                    while(iter2 != WidthAreas.end())
                    {
                        if(InsideOf(iter2.value(),dotPoint))
                        {
                            Process = false;
                            switch(iter2.key()){
                                case PenWidthChange::THIN:
                                {
                                    if(tmpwidth>(int)PenWidth::ONE){
                                        tmpwidth = (PenWidth)((int)tmpwidth-1);
                                        emit OnWidthChanged(tmpwidth);
                                        WidthChangedEvent(tmpwidth);
                                    }
                                    break;
                                }
                                case PenWidthChange::BOLD:
                                {
                                    if(tmpwidth<(int)PenWidth::FIVE){
                                        tmpwidth = (PenWidth)((int)tmpwidth+1);
                                        emit OnWidthChanged(tmpwidth);
                                        WidthChangedEvent(tmpwidth);
                                    }
                                    break;
                                }
                            }
                            return ;
                        }
                        iter2++;
                    }
                }
                if(Process){
                    emit OnPenMove(pageaddress,dotPoint);
                    PenMoveEvent(pageaddress,dotPoint);
                }
            }
            break;
        }
        case DotType::PEN_UP:
        {
            IsPenDown = false;
            if(Process){
                emit OnPenMove(pageaddress,dotPoint);
                PenMoveEvent(pageaddress,dotPoint);
                emit OnPenUp();
                PenUpEvent();
            }
            Process = true;
            break;
        }
    }
}

PenManager* PenManager::GetInstance()
{
    if(instance == NULL){
        instance = new PenManager();
    }
    return instance;
}

PenManager::PenColor PenManager::GetCurrentPenColor()
{
    return tmpcolor;
}

PenManager::PenWidth PenManager::GetCurrentPenWidth()
{
    return tmpwidth;
}

QString PenManager::GetPenSerial()
{
    return PenSerial;
}

PenManager *PenManager::whenConnect(const function<void (QString)>& event)
{
    ConnectEvent=event;
    return this;
}

PenManager *PenManager::whenDisConnect(const function<void ()>& event)
{
    DisConnectEvent=event;
    return this;
}

PenManager *PenManager::whenPenDown(const function<void ()>& event)
{
    PenDownEvent=event;
    return this;
}

PenManager *PenManager::whenPenUp(const function<void ()>& event)
{
    PenUpEvent=event;
    return this;
}

PenManager *PenManager::whenPenMove(const function<void (QString, QPoint)>& event)
{
    PenMoveEvent=event;
    return this;
}

PenManager *PenManager::whenSubmitDot(const function<void ()>& event)
{
    SubmitEvent=event;
    return this;
}

PenManager *PenManager::whenColorChanged(const function<void (PenColor)>& event)
{
    ColorChangedEvent=event;
    return this;
}

PenManager *PenManager::whenWidthChanged(const function<void (PenManager::PenWidth)>& event)
{
    WidthChangedEvent=event;
    return this;
}

PenManager *PenManager::whenClear(const function<void ()>& event)
{
    ClearEvent=event;
    return this;
}

PenManager *PenManager::whenCancel(const function<void ()> & event)
{
    CancelEvent = event;
    return this;
}

PenManager *PenManager::Reset()
{
    tmpwidth = (PenWidth)1;
    tmpcolor = (PenColor)0;
    ColorChangedEvent(tmpcolor);
    WidthChangedEvent(tmpwidth);
    return this;
}

PenManager *PenManager::SetSubmitArea(const QRect &area)
{
    SubmitArea = area;
    return this;
}

