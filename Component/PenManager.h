#ifndef PENMANAGER_H
#define PENMANAGER_H

#include <QObject>
#include "Include/TQLComm.h"
#include "Include/hidapi.h"
#include "Qt_Heads.h"

using namespace std;
class PenManager : public QObject
{
        Q_OBJECT

    public :
        enum PenColor{
            BLACK = 0,
            RED = 1,
            BLUE = 2,
            GREEN = 3
        };
        enum PenWidth{
            ONE = 1,
            TWO = 2,
            THREE = 3,
            FOUR = 4,
            FIVE = 5,
        };
        enum PenWidthChange{
            THIN,
            BOLD
        };
        PenManager();
        virtual ~PenManager(){}
    signals:
        void OnPenDown();
        void OnPenMove(QString pageAddress,QPoint point);
        void OnPenUp();
        void OnPenConnected(QString penSerial);
        void OnPenDisconnect();
        void OnColorChanged(int color);
        void OnWidthChanged(int width);
        void OnSubmit();
        void OnClear();
        void OnCancel();
    private:       
        float TransDot = 1.524*80/3;
        bool Process = true;
        bool IsPenDown = false;
        float scale = 80.0f/3;
        QPoint lastpoint = QPoint(-1,-1);
        QMap<PenColor,QRectF> ColorAreas;
        QMap<PenWidthChange,QRectF> WidthAreas;
        QRectF ClearArea;
        QRectF SubmitArea;
        QRectF CancelArea;
        void* PenHandle = NULL;
        QString PenSerial = "";

        static PenManager* instance;
        PenWidth tmpwidth = (PenWidth)1;
        PenColor tmpcolor = (PenColor)0;

        function<void(Dot*)> NewDotEvents= [](Dot*){};
        function<void(QString)>ConnectEvent = [](QString){};
        function<void()> DisConnectEvent = []{};
        function<void()> PenDownEvent= []{};
        function<void()> PenUpEvent= []{};
        function<void(QString,QPoint)>PenMoveEvent= [](QString,QPoint){};
        function<void(PenColor)> ColorChangedEvent= [](PenColor){};
        function<void(PenWidth)> WidthChangedEvent= [](PenWidth){};
        function<void()> ClearEvent= []{};
        function<void()> CancelEvent= []{};
        function<void()> SubmitEvent= []{};

    public:
        void SetPenSerial(QString penSerial);       
        bool IsConnected();
        void OnPenConnect(QString penSerial);
        void OnPenDisConnect();
        void OnNewDot(Dot *dot);
        static PenManager* GetInstance();
        PenColor GetCurrentPenColor();
        PenWidth GetCurrentPenWidth();
        QString GetPenSerial();

        PenManager *whenConnect(const function<void(QString)> & event);
        PenManager *whenDisConnect(const function<void()> & event);

        PenManager *whenPenDown(const function<void()> & event);
        PenManager *whenPenUp(const function<void()> & event);
        PenManager *whenPenMove(const function<void(QString pageAddress,QPoint point)> & event);

        PenManager *whenSubmitDot(const function<void()> & event);
        PenManager *whenColorChanged(const function<void(PenColor)> & event);
        PenManager *whenWidthChanged(const function<void(PenWidth)> & event);
        PenManager *whenClear(const function<void()> & event);
        PenManager *whenCancel(const function<void()> & event);

        PenManager *Reset();

        PenManager *SetSubmitArea(const QRect & area);
};
#define PEN_MANAGER PenManager::GetInstance()

#endif // PENMANAGER_H
