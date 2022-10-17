#include "TQLCallBack.h"
#include <time.h>
#include <QtConcurrent/QtConcurrent>
#include <Component/PenManager.h>
PENHANDLE handle = 0;

int LastRecviceDotTime = 0;
int LastRecviceOffDotTime = 0;
int ConnectTime = 0;

void * ConnectPenThread(void * lpParameter)
{
    if(handle==NULL)
    {
        handle = Init();
    }
    if(handle!=NULL)
    {
        if(!PenManager::GetInstance()->IsConnected())
        {
            QtConcurrent::run([=]{
                QThread::msleep(10);
                while(!GetMCUCode(handle)){
                }
            });
        }
    }




    //    handle = Init();

    //    if(handle ==NULL){
    //        system("chmod -R 777 /dev/hid*");
    //        system("chmod -R 777 /dev/usb/hid*");
    //        handle = Init();
    //    }
    //    if(handle == NULL){
    //        system("pkexec chmod -R 777 /dev/hid* \n chmod -R 777 /dev/usb/hid*");
    //        handle = Init();
    //    }
    //    if (handle == NULL)
    //    {
    //    }else{
    //        GetMCUCode(handle);
    //    }
    return 0;
}

void InitCallBack()
{

    InitCallBackHIDGetReady(TQLonHIDGetReady);

    InitCallBackConnectionStatus(TQLonConnectionStatus);

    InitCallBackGetPenLocalName(TQLonGetPenLocalName);

    InitCallBackGetMacAddress(TQLonGetMacAddress);

    InitCallBackGetBatteryPower(TQLonGetBatteryPower);

    InitCallBackGetUsedMemory(TQLonGetUsedMemory);

    InitCallBackGetFWVersion(TQLonGetFWVersion);

    InitCallBackGetMCUFWVersion(TQLonGetMCUFWVersion);

    InitCallBackGetMCUCode(TQLonGetMCUCode);

    InitCallBackGetAutoPowerOnMode(TQLonGetAutoPowerOnMode);

    InitCallBackGetAutoPowerOffTime(TQLonGetAutoPowerOffTime);

    InitCallBackGetBeepStatus(TQLonGetBeepStatus);

    InitCallBackGetSensitivityLevel(TQLonGetSensitivityLevel);

    InitCallBackGetPenColor(TQLonGetPenColor);

    InitCallBackGetRTC(TQLonGetRTC);

    InitCallBackGetOfflineDataNo(TQLonGetOfflineDataNo);

    InitCallBackGetPressureCalibrationData(TQLonGetPressureCalibrationData);

    InitCallBackGetCustomerID(TQLonGetCustomerID);

    InitCallBackGetElementCode(TQLonGetElementCode);

    InitCallBackGetOID4ElementCode(TQLonGetOID4ElementCode);

    InitCallBackGetOIDType(TQLonGetOIDType);

    InitCallBackStartDownloadOfflineData(TQLonStartDownloadOfflineData);

    InitCallBackStopDownloadOfflineData(TQLonStopDownloadOfflineData);

    InitCallBackEndOfDownloadOfflineData(TQLonEndOfDownloadOfflineData);

    InitCallBackConfirmReceiveOfflineData(TQLonConfirmReceiveOfflineData);

    InitCallBackRemoveOfflineData(TQLonRemoveOfflineData);

    InitCallBackPauseOfflineData(TQLonPauseOfflineData);

    InitCallBackContinueOfflineData(TQLonContinueOfflineData);

    InitCallBackSetPenLocalName(TQLonSetPenLocalName);

    InitCallBackSetAutoPowerOnMode(TQLonSetAutoPowerOnMode);

    InitCallBackSetAutoPowerOffTime(TQLonSetAutoPowerOffTime);

    InitCallBackSetBeepStatus(TQLonSetBeepStatus);

    InitCallBackSetSensitivityLevel(TQLonSetSensitivityLevel);

    InitCallBackSetPenColor(TQLonSetPenColor);

    InitCallBackWriteRTC(TQLonWriteRTC);

    InitCallBackSetElementCode(TQLonSetElementCode);

    InitCallBackSetOIDType(TQLonSetOIDType);

    InitCallBackSetCustomerID(TQLonSetCustomerID);

    InitCallBackReceiveDot(TQLonReceiveDot);

    InitCallBackReceiveOriginalDot(TQLonReceiveOriginalDot);

    InitCallBackReceiveOfflineData(TQLonReceiveOfflineData);

    InitCallBackUpDown(TQLonUpDown);

    pthread_t id;
    pthread_create(&id, 0, ConnectPenThread, 0);
}

void TQLonHIDGetReady(PENHANDLE handle, bool bReady)
{
    //    if (bReady == false)
    //    {
    //        Close(handle);
    //        ::handle = 0;
    //        QString str(QString::fromLocal8Bit("蓝牙狗已断开连接！"));
    //        //PEN_MANAGER->OnPenDisConnect();
    //    }
    //    else
    //    {
    //        ::handle = handle;
    //        QString str(QString::fromLocal8Bit("蓝牙狗已连接！"));
    //        //PEN_MANAGER->OnPenConnect(handle);
    //    }
}

void TQLonConnectionStatus(PENHANDLE handle, bool bConnected)
{
    if (bConnected == false)
    {


        QString str(QString::fromLocal8Bit("智能笔已断开连接！"));

        PEN_MANAGER->OnPenDisConnect();
    }
    else
    {
        QtConcurrent::run([=]{
            QThread::msleep(10);
            while(!GetMCUCode(handle)){

            }
        });

    }
}


void TQLonGetMCUCode(PENHANDLE handle, char * strData)
{


    QString str(QString::fromLocal8Bit("智能笔已连接！"));

    PEN_MANAGER->OnPenConnect(QString(strData));

}


void TQLonGetPenLocalName(PENHANDLE handle, char * localName)
{

}

void TQLonGetMacAddress(PENHANDLE handle, char * macAddress)
{

}

void TQLonGetBatteryPower(PENHANDLE handle, short Data)
{

}


void TQLonGetUsedMemory(PENHANDLE handle, short Data)
{

}


void TQLonGetFWVersion(PENHANDLE handle, char * strData)
{

}


void TQLonGetMCUFWVersion(PENHANDLE handle, char * strData)
{

}




void TQLonGetAutoPowerOnMode(PENHANDLE handle, bool bSetOn)
{

}


void TQLonGetAutoPowerOffTime(PENHANDLE handle, short Data)
{

}


void TQLonGetBeepStatus(PENHANDLE handle, bool bSetOn)
{

}


void TQLonGetSensitivityLevel(PENHANDLE handle, short Data)
{

}


void TQLonGetPenColor(PENHANDLE handle, short Data)
{

}

void TQLonGetRTC(PENHANDLE handle, unsigned long Data)
{

}


void TQLonGetOfflineDataNo(PENHANDLE handle, int Data)
{

}


void TQLonGetPressureCalibrationData(PENHANDLE handle, int LData, int HData)
{

}

void TQLonGetCustomerID(PENHANDLE handle, int ID1, int ID2)
{

}


/*
*@notes 该方法目前暂停使用*/
void TQLonGetElementCode(PENHANDLE handle, int OID, int SID, int Size)
{

}

void TQLonGetOID4ElementCode(PENHANDLE handle, long index)
{

}

void TQLonGetOIDType(PENHANDLE handle, int oType)
{

}

void TQLonStartDownloadOfflineData(PENHANDLE handle, bool bStart)
{

}

void TQLonStopDownloadOfflineData(PENHANDLE handle, bool bStart)
{

}


void TQLonEndOfDownloadOfflineData(PENHANDLE handle, bool bEnd)
{

}

void TQLonConfirmReceiveOfflineData(PENHANDLE handle, bool bSuccess)
{

}


void TQLonRemoveOfflineData(PENHANDLE handle, bool bRemoved)
{

}


void TQLonPauseOfflineData(PENHANDLE handle, bool bSuccess)
{

}


void TQLonContinueOfflineData(PENHANDLE handle, bool bSuccess)
{

}


void TQLonSetPenLocalName(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetAutoPowerOnMode(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetAutoPowerOffTime(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetBeepStatus(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetSensitivityLevel(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetPenColor(PENHANDLE handle, bool bsuccess)
{

}

void TQLonWriteRTC(PENHANDLE handle, bool bsuccess)
{

}

void TQLonSetElementCode(PENHANDLE handle, bool bSuccess)
{

}

void TQLonSetOIDType(PENHANDLE handle, bool bSuccess)
{

}

void TQLonSetCustomerID(PENHANDLE handle, bool bsuccess)
{

}

void TQLonReceiveDot(PENHANDLE handle, Dot* dot, int count)
{
    if(PEN_MANAGER->IsConnected())
    {
        PEN_MANAGER->OnNewDot(dot);
        LastRecviceDotTime = time(0);
    }
    else
    {
        GetMCUCode(handle);
    }
}

void TQLonReceiveOriginalDot(PENHANDLE handle, Dot* dot, int count)
{

}

void TQLonReceiveOfflineData(PENHANDLE handle, Dot* dot, int count)
{

}

void TQLonUpDown(PENHANDLE handle, bool isUp, int count)
{

}
