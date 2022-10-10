#pragma once
#include "TQLComm.h"
extern PENHANDLE handle;
extern int LastRecviceDotTime;
extern int LastRecviceOffDotTime;
/**
*@brief onHIDGetReady 智能笔蓝牙狗连接状态回调函数
*@param[in] handle 智能笔句柄
*@param[in] bReady 智能笔蓝牙狗当前连接状态
*@return 无
*@notes 该回调只适用使用蓝牙狗连接智能笔
*/
void TQLonHIDGetReady(PENHANDLE handle, bool bReady);//获取蓝牙狗是否连接



/**
*@brief onConnectionStatus 智能笔连接状态回调函数
*@param[in] handle 智能笔句柄
*@param[in] bConnected 智能笔当前连接状态
*@return 无
*/
void TQLonConnectionStatus(PENHANDLE handle, bool bConnected);//获取智能笔是否连接




/**
*@brief onGetPenLocalName 智能笔当前设置名称回调函数
*@param[in] handle 智能笔句柄
*@param[in] localName 智能笔当前设置名称
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
void TQLonGetPenLocalName(PENHANDLE handle, char * localName);//获取智能笔名





/**
*@brief onGetMacAddress 智能笔蓝牙地址回调函数
*@param[in] handle 智能笔句柄
*@param[in] macAddress 智能笔蓝牙地址
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
void TQLonGetMacAddress(PENHANDLE handle, char * macAddress);//获取蓝牙地址





/**
*@brief onGetBatteryPower 智能笔电量回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔电量
*@return 无
*@notes 该回调只适用使用带有电池的智能笔
*/
void TQLonGetBatteryPower(PENHANDLE handle, short Data);//读取电量





/**
*@brief onGetUsedMemory 智能笔lash内存回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔lash内存
*@return 无
*/
void TQLonGetUsedMemory(PENHANDLE handle, short Data);//读取flash内存




/**
*@brief onGetFWVersion 智能笔蓝牙固件版本回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔蓝牙固件版本
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
void TQLonGetFWVersion(PENHANDLE handle, char * strData);//获取蓝牙固件版本




/**
*@brief onGetMCUFWVersion 智能笔MCU固件版本回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔MCU固件版本
*@return 无
*/
void TQLonGetMCUFWVersion(PENHANDLE handle, char * strData);//获取MCU固件版本


/*
*@brief onGetMCUFWVersion 智能笔MCU序列号回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔MCU固件版本
*@return 无
*/
void TQLonGetMCUCode(PENHANDLE handle, char * strData);//获取MCU固件版本

/**
*@brief onGetMCUFWVersion 智能笔笔尖压力是否唤醒智能笔回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 智能笔笔尖压力是否唤醒智能笔
*@return 无
*/
void TQLonGetAutoPowerOnMode(PENHANDLE handle, bool bSetOn);//获取笔尖压力是否唤醒智能笔





/**
*@brief onGetMCUFWVersion 智能笔自动关机时间回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔自动关机时间
*@return 无
*/
void TQLonGetAutoPowerOffTime(PENHANDLE handle, short Data);//获取自动关机时间



/**
*@brief onGetBeepStatus 智能笔蜂鸣器是否响动回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 智能笔蜂鸣器是否响动
*@return 无
*/
void TQLonGetBeepStatus(PENHANDLE handle, bool bSetOn);//获取蜂鸣器是否响动





/**
*@brief onGetBeepStatus 智能笔压力敏感度回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔压力敏感度
*@return 无
*/
void TQLonGetSensitivityLevel(PENHANDLE handle, short Data);//获取压力敏感度





/**
*@brief onGetPenColor 智能笔led当前颜色回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔led当前颜色
*@return 无
*/
void TQLonGetPenColor(PENHANDLE handle, short Data);//获取智能笔led当前颜色



/**
*@brief onGetRTC 智能笔RTC时间回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔RTC时间
*@return 无
*/
void TQLonGetRTC(PENHANDLE handle, unsigned long Data);//获取RTC时间




/**
*@brief onGetOfflineDataNo 智能笔离线数据量回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔离线数据量
*@return 无
*/
void TQLonGetOfflineDataNo(PENHANDLE handle, int Data);//获取离线数据量




/**
*@brief onGetPressureCalibrationData 智能笔压力矫正值回调函数
*@param[in] handle 智能笔句柄
*@param[in] LData 智能笔压力20g矫正值
*@param[in] HData 智能笔压力300g矫正值
*@return 无
*/
void TQLonGetPressureCalibrationData(PENHANDLE handle, int LData, int HData);//读取压力矫正值




/**
*@brief onGetCustomerID 智能笔Customer ID回调函数
*@param[in] handle 智能笔句柄
*@param[in] ID1 智能笔Customer ID1值
*@param[in] ID2 智能笔Customer ID2值
*@return 无
*/
void TQLonGetCustomerID(PENHANDLE handle, int ID1, int ID2);//读取Customer ID




/*

*@notes 该方法目前暂停使用*/
void TQLonGetElementCode(PENHANDLE handle, int OID, int SID, int Size);//获取码点数据格式



/**
*@brief onGetCustomerID 智能笔OID4码点数据格式回调函数
*@param[in] handle 智能笔句柄
*@param[in] index OID4码点数据格式
*@return 无
*/
void TQLonGetOID4ElementCode(PENHANDLE handle, long index);//获取OID4码点数据格式




/**
*@brief onGetOIDType 智能笔码点类型回调函数
*@param[in] handle 智能笔句柄
*@param[in] oType 码点类型
*@return 无
*/
void TQLonGetOIDType(PENHANDLE handle, int oType);//获取码点类型



/**
*@brief onStartDownloadOfflineData 智能笔启动离线数据是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bStart 启动离线数据是否成功
*@return 无
*/
void TQLonStartDownloadOfflineData(PENHANDLE handle, bool bStart);//启动离线数据是否成功



/**
*@brief onStopDownloadOfflineData 智能笔停止离线数据是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bStart 停止离线数据是否成功
*@return 无
*/
void TQLonStopDownloadOfflineData(PENHANDLE handle, bool bStart);//停止离线数据是否成功




/**
*@brief onEndOfDownloadOfflineData 智能笔离线数据传输完成回调函数
*@param[in] handle 智能笔句柄
*@param[in] bEnd 离线数据传输完成
*@return 无
*/
void TQLonEndOfDownloadOfflineData(PENHANDLE handle, bool bEnd);//离线数据传输完成




/**
*@brief onConfirmReceiveOfflineData 智能笔确定离线数据接收完成回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 确定离线数据接收完成
*@return 无
*/
void TQLonConfirmReceiveOfflineData(PENHANDLE handle, bool bSuccess);//确定离线数据接收完成



/**
*@brief onRemoveOfflineData 智能笔删除离线数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] bRemoved 删除离线数据
*@return 无
*/
void TQLonRemoveOfflineData(PENHANDLE handle, bool bRemoved);//删除离线数据



/**
*@brief onPauseOfflineData 智能笔暂停离线数据接收回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 暂停离线数据接收
*@return 无
*/
void TQLonPauseOfflineData(PENHANDLE handle, bool bSuccess);//暂停离线数据接收


/**
*@brief onContinueOfflineData 智能笔继续离线数据接收回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 继续离线数据接收
*@return 无
*/
void TQLonContinueOfflineData(PENHANDLE handle, bool bSuccess);//继续离线数据接收



/**
*@brief onSetPenLocalName 智能笔设置智能笔名是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置智能笔名是否成功
*@return 无
*/
void TQLonSetPenLocalName(PENHANDLE handle, bool bsuccess);//设置智能笔名是否成功




/**
*@brief onSetAutoPowerOnMode 智能笔设置笔尖压力是否唤醒智能笔是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置笔尖压力是否唤醒智能笔是否成功
*@return 无
*/
void TQLonSetAutoPowerOnMode(PENHANDLE handle, bool bsuccess);//设置笔尖压力是否唤醒智能笔是否成功




/**
*@brief onSetAutoPowerOffTime 智能笔设置自动关机时间是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置自动关机时间是否成功
*@return 无
*/
void TQLonSetAutoPowerOffTime(PENHANDLE handle, bool bsuccess);//设置自动关机时间是否成功




/**
*@brief onSetBeepStatus 智能笔设置蜂鸣器是否响动是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置蜂鸣器是否响动是否成功
*@return 无
*/
void TQLonSetBeepStatus(PENHANDLE handle, bool bsuccess);//设置蜂鸣器是否响动是否成功



/**
*@brief onSetSensitivityLevel 智能笔设置压力敏感度是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置压力敏感度是否成功
*@return 无
*/
void TQLonSetSensitivityLevel(PENHANDLE handle, bool bsuccess);//设置压力敏感度是否成功


/**
*@brief onSetPenColor 智能笔设置智能笔LED颜色是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置智能笔LED颜色是否成功
*@return 无
*/
void TQLonSetPenColor(PENHANDLE handle, bool bsuccess);//设置智能笔LED颜色是否成功





/**
*@brief onWriteRTC 智能笔设置RTC时间是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置RTC时间是否成功
*@return 无
*/
void TQLonWriteRTC(PENHANDLE handle, bool bsuccess);//设置RTC时间是否成功



/**
*@brief onSetElementCode 智能笔设置码点数据格式是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置码点数据格式是否成功
*@return 无
*/
void TQLonSetElementCode(PENHANDLE handle, bool bSuccess);//设置码点数据格式是否成功




/**
*@brief onSetElementCode 智能笔设置码点类型是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置码点类型是否成功
*@return 无
*/
void TQLonSetOIDType(PENHANDLE handle, bool bSuccess);//设置码点类型是否成功





/**
*@brief onSetCustomerID 智能笔设置Customer ID是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置Customer ID是否成功
*@return 无
*/
void TQLonSetCustomerID(PENHANDLE handle, bool bsuccess);//设置Customer ID是否成功




/**
*@brief onReceiveDot 智能笔实时笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 实时笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
void TQLonReceiveDot(PENHANDLE handle, Dot* dot, int count);//实时笔迹数据




/**
*@brief onReceiveOriginalDot 智能笔过滤前实时笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 过滤前实时笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
void TQLonReceiveOriginalDot(PENHANDLE handle, Dot* dot, int count);//过滤前实时笔迹数据



/**
*@brief onReceiveOfflineData 智能笔离线笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 离线笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
void TQLonReceiveOfflineData(PENHANDLE handle, Dot* dot, int count);//离线笔迹数据




void TQLonUpDown(PENHANDLE handle, bool isUp, int count);


void InitCallBack();


