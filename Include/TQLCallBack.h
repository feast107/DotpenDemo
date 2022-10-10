#pragma once
#include "TQLComm.h"
extern PENHANDLE handle;
extern int LastRecviceDotTime;
extern int LastRecviceOffDotTime;
/**
*@brief onHIDGetReady ���ܱ�����������״̬�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bReady ���ܱ���������ǰ����״̬
*@return ��
*@notes �ûص�ֻ����ʹ���������������ܱ�
*/
void TQLonHIDGetReady(PENHANDLE handle, bool bReady);//��ȡ�������Ƿ�����



/**
*@brief onConnectionStatus ���ܱ�����״̬�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bConnected ���ܱʵ�ǰ����״̬
*@return ��
*/
void TQLonConnectionStatus(PENHANDLE handle, bool bConnected);//��ȡ���ܱ��Ƿ�����




/**
*@brief onGetPenLocalName ���ܱʵ�ǰ�������ƻص�����
*@param[in] handle ���ܱʾ��
*@param[in] localName ���ܱʵ�ǰ��������
*@return ��
*@notes �ûص�ֻ����ʹ���������ܱ�
*/
void TQLonGetPenLocalName(PENHANDLE handle, char * localName);//��ȡ���ܱ���





/**
*@brief onGetMacAddress ���ܱ�������ַ�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] macAddress ���ܱ�������ַ
*@return ��
*@notes �ûص�ֻ����ʹ���������ܱ�
*/
void TQLonGetMacAddress(PENHANDLE handle, char * macAddress);//��ȡ������ַ





/**
*@brief onGetBatteryPower ���ܱʵ����ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱʵ���
*@return ��
*@notes �ûص�ֻ����ʹ�ô��е�ص����ܱ�
*/
void TQLonGetBatteryPower(PENHANDLE handle, short Data);//��ȡ����





/**
*@brief onGetUsedMemory ���ܱ�lash�ڴ�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ�lash�ڴ�
*@return ��
*/
void TQLonGetUsedMemory(PENHANDLE handle, short Data);//��ȡflash�ڴ�




/**
*@brief onGetFWVersion ���ܱ������̼��汾�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] strData ���ܱ������̼��汾
*@return ��
*@notes �ûص�ֻ����ʹ���������ܱ�
*/
void TQLonGetFWVersion(PENHANDLE handle, char * strData);//��ȡ�����̼��汾




/**
*@brief onGetMCUFWVersion ���ܱ�MCU�̼��汾�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] strData ���ܱ�MCU�̼��汾
*@return ��
*/
void TQLonGetMCUFWVersion(PENHANDLE handle, char * strData);//��ȡMCU�̼��汾


/*
*@brief onGetMCUFWVersion ���ܱ�MCU���кŻص�����
*@param[in] handle ���ܱʾ��
*@param[in] strData ���ܱ�MCU�̼��汾
*@return ��
*/
void TQLonGetMCUCode(PENHANDLE handle, char * strData);//��ȡMCU�̼��汾

/**
*@brief onGetMCUFWVersion ���ܱʱʼ�ѹ���Ƿ������ܱʻص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSetOn ���ܱʱʼ�ѹ���Ƿ������ܱ�
*@return ��
*/
void TQLonGetAutoPowerOnMode(PENHANDLE handle, bool bSetOn);//��ȡ�ʼ�ѹ���Ƿ������ܱ�





/**
*@brief onGetMCUFWVersion ���ܱ��Զ��ػ�ʱ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ��Զ��ػ�ʱ��
*@return ��
*/
void TQLonGetAutoPowerOffTime(PENHANDLE handle, short Data);//��ȡ�Զ��ػ�ʱ��



/**
*@brief onGetBeepStatus ���ܱʷ������Ƿ��춯�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSetOn ���ܱʷ������Ƿ��춯
*@return ��
*/
void TQLonGetBeepStatus(PENHANDLE handle, bool bSetOn);//��ȡ�������Ƿ��춯





/**
*@brief onGetBeepStatus ���ܱ�ѹ�����жȻص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ�ѹ�����ж�
*@return ��
*/
void TQLonGetSensitivityLevel(PENHANDLE handle, short Data);//��ȡѹ�����ж�





/**
*@brief onGetPenColor ���ܱ�led��ǰ��ɫ�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ�led��ǰ��ɫ
*@return ��
*/
void TQLonGetPenColor(PENHANDLE handle, short Data);//��ȡ���ܱ�led��ǰ��ɫ



/**
*@brief onGetRTC ���ܱ�RTCʱ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ�RTCʱ��
*@return ��
*/
void TQLonGetRTC(PENHANDLE handle, unsigned long Data);//��ȡRTCʱ��




/**
*@brief onGetOfflineDataNo ���ܱ������������ص�����
*@param[in] handle ���ܱʾ��
*@param[in] Data ���ܱ�����������
*@return ��
*/
void TQLonGetOfflineDataNo(PENHANDLE handle, int Data);//��ȡ����������




/**
*@brief onGetPressureCalibrationData ���ܱ�ѹ������ֵ�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] LData ���ܱ�ѹ��20g����ֵ
*@param[in] HData ���ܱ�ѹ��300g����ֵ
*@return ��
*/
void TQLonGetPressureCalibrationData(PENHANDLE handle, int LData, int HData);//��ȡѹ������ֵ




/**
*@brief onGetCustomerID ���ܱ�Customer ID�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] ID1 ���ܱ�Customer ID1ֵ
*@param[in] ID2 ���ܱ�Customer ID2ֵ
*@return ��
*/
void TQLonGetCustomerID(PENHANDLE handle, int ID1, int ID2);//��ȡCustomer ID




/*

*@notes �÷���Ŀǰ��ͣʹ��*/
void TQLonGetElementCode(PENHANDLE handle, int OID, int SID, int Size);//��ȡ������ݸ�ʽ



/**
*@brief onGetCustomerID ���ܱ�OID4������ݸ�ʽ�ص�����
*@param[in] handle ���ܱʾ��
*@param[in] index OID4������ݸ�ʽ
*@return ��
*/
void TQLonGetOID4ElementCode(PENHANDLE handle, long index);//��ȡOID4������ݸ�ʽ




/**
*@brief onGetOIDType ���ܱ�������ͻص�����
*@param[in] handle ���ܱʾ��
*@param[in] oType �������
*@return ��
*/
void TQLonGetOIDType(PENHANDLE handle, int oType);//��ȡ�������



/**
*@brief onStartDownloadOfflineData ���ܱ��������������Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bStart �������������Ƿ�ɹ�
*@return ��
*/
void TQLonStartDownloadOfflineData(PENHANDLE handle, bool bStart);//�������������Ƿ�ɹ�



/**
*@brief onStopDownloadOfflineData ���ܱ�ֹͣ���������Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bStart ֹͣ���������Ƿ�ɹ�
*@return ��
*/
void TQLonStopDownloadOfflineData(PENHANDLE handle, bool bStart);//ֹͣ���������Ƿ�ɹ�




/**
*@brief onEndOfDownloadOfflineData ���ܱ��������ݴ�����ɻص�����
*@param[in] handle ���ܱʾ��
*@param[in] bEnd �������ݴ������
*@return ��
*/
void TQLonEndOfDownloadOfflineData(PENHANDLE handle, bool bEnd);//�������ݴ������




/**
*@brief onConfirmReceiveOfflineData ���ܱ�ȷ���������ݽ�����ɻص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ȷ���������ݽ������
*@return ��
*/
void TQLonConfirmReceiveOfflineData(PENHANDLE handle, bool bSuccess);//ȷ���������ݽ������



/**
*@brief onRemoveOfflineData ���ܱ�ɾ���������ݻص�����
*@param[in] handle ���ܱʾ��
*@param[in] bRemoved ɾ����������
*@return ��
*/
void TQLonRemoveOfflineData(PENHANDLE handle, bool bRemoved);//ɾ����������



/**
*@brief onPauseOfflineData ���ܱ���ͣ�������ݽ��ջص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ��ͣ�������ݽ���
*@return ��
*/
void TQLonPauseOfflineData(PENHANDLE handle, bool bSuccess);//��ͣ�������ݽ���


/**
*@brief onContinueOfflineData ���ܱʼ����������ݽ��ջص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess �����������ݽ���
*@return ��
*/
void TQLonContinueOfflineData(PENHANDLE handle, bool bSuccess);//�����������ݽ���



/**
*@brief onSetPenLocalName ���ܱ��������ܱ����Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess �������ܱ����Ƿ�ɹ�
*@return ��
*/
void TQLonSetPenLocalName(PENHANDLE handle, bool bsuccess);//�������ܱ����Ƿ�ɹ�




/**
*@brief onSetAutoPowerOnMode ���ܱ����ñʼ�ѹ���Ƿ������ܱ��Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ���ñʼ�ѹ���Ƿ������ܱ��Ƿ�ɹ�
*@return ��
*/
void TQLonSetAutoPowerOnMode(PENHANDLE handle, bool bsuccess);//���ñʼ�ѹ���Ƿ������ܱ��Ƿ�ɹ�




/**
*@brief onSetAutoPowerOffTime ���ܱ������Զ��ػ�ʱ���Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess �����Զ��ػ�ʱ���Ƿ�ɹ�
*@return ��
*/
void TQLonSetAutoPowerOffTime(PENHANDLE handle, bool bsuccess);//�����Զ��ػ�ʱ���Ƿ�ɹ�




/**
*@brief onSetBeepStatus ���ܱ����÷������Ƿ��춯�Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ���÷������Ƿ��춯�Ƿ�ɹ�
*@return ��
*/
void TQLonSetBeepStatus(PENHANDLE handle, bool bsuccess);//���÷������Ƿ��춯�Ƿ�ɹ�



/**
*@brief onSetSensitivityLevel ���ܱ�����ѹ�����ж��Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ����ѹ�����ж��Ƿ�ɹ�
*@return ��
*/
void TQLonSetSensitivityLevel(PENHANDLE handle, bool bsuccess);//����ѹ�����ж��Ƿ�ɹ�


/**
*@brief onSetPenColor ���ܱ��������ܱ�LED��ɫ�Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess �������ܱ�LED��ɫ�Ƿ�ɹ�
*@return ��
*/
void TQLonSetPenColor(PENHANDLE handle, bool bsuccess);//�������ܱ�LED��ɫ�Ƿ�ɹ�





/**
*@brief onWriteRTC ���ܱ�����RTCʱ���Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ����RTCʱ���Ƿ�ɹ�
*@return ��
*/
void TQLonWriteRTC(PENHANDLE handle, bool bsuccess);//����RTCʱ���Ƿ�ɹ�



/**
*@brief onSetElementCode ���ܱ�����������ݸ�ʽ�Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ����������ݸ�ʽ�Ƿ�ɹ�
*@return ��
*/
void TQLonSetElementCode(PENHANDLE handle, bool bSuccess);//����������ݸ�ʽ�Ƿ�ɹ�




/**
*@brief onSetElementCode ���ܱ�������������Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ������������Ƿ�ɹ�
*@return ��
*/
void TQLonSetOIDType(PENHANDLE handle, bool bSuccess);//������������Ƿ�ɹ�





/**
*@brief onSetCustomerID ���ܱ�����Customer ID�Ƿ�ɹ��ص�����
*@param[in] handle ���ܱʾ��
*@param[in] bSuccess ����Customer ID�Ƿ�ɹ�
*@return ��
*/
void TQLonSetCustomerID(PENHANDLE handle, bool bsuccess);//����Customer ID�Ƿ�ɹ�




/**
*@brief onReceiveDot ���ܱ�ʵʱ�ʼ����ݻص�����
*@param[in] handle ���ܱʾ��
*@param[in] dot ʵʱ�ʼ�����
*@param[in] count ��ǰCountֵ
*@return ��
*/
void TQLonReceiveDot(PENHANDLE handle, Dot* dot, int count);//ʵʱ�ʼ�����




/**
*@brief onReceiveOriginalDot ���ܱʹ���ǰʵʱ�ʼ����ݻص�����
*@param[in] handle ���ܱʾ��
*@param[in] dot ����ǰʵʱ�ʼ�����
*@param[in] count ��ǰCountֵ
*@return ��
*/
void TQLonReceiveOriginalDot(PENHANDLE handle, Dot* dot, int count);//����ǰʵʱ�ʼ�����



/**
*@brief onReceiveOfflineData ���ܱ����߱ʼ����ݻص�����
*@param[in] handle ���ܱʾ��
*@param[in] dot ���߱ʼ�����
*@param[in] count ��ǰCountֵ
*@return ��
*/
void TQLonReceiveOfflineData(PENHANDLE handle, Dot* dot, int count);//���߱ʼ�����




void TQLonUpDown(PENHANDLE handle, bool isUp, int count);


void InitCallBack();


