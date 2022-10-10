#pragma once
#include <stdbool.h>
#ifndef _WIN32
#ifndef __cplusplus
#define TQLCOMM_API extern
#else
#define TQLCOMM_API extern "C"
#endif
#else
#include <windows.h>
#ifndef __cplusplus
#ifdef TQLCOMM_EXPORTS
#define TQLCOMM_API extern	__declspec(dllexport)
#else
#define TQLCOMM_API extern	__declspec(dllimport)
#endif
#else
#ifdef TQLCOMM_EXPORTS
#define TQLCOMM_API extern "C"  __declspec(dllexport)
#else
#define TQLCOMM_API extern "C"  __declspec(dllimport)
#endif
#endif
#endif

#define PENHANDLE void *

/** @brief 智能笔坐标点操作类型 */
typedef enum DotType
{
	/** @brief 智能笔按下 */
	PEN_DOWN = 0,

	/** @brief 智能笔移动 */
	PEN_MOVE = 1,

	/** @brief 智能笔弹起 */
	PEN_UP = 2,

	/** @brief 智能笔悬停 */
	PEN_HOVER = 3
}DotType;

/** @brief 智能笔坐标点数据 */
typedef struct Dot
{
	/** @brief 坐标点ID */
	int count;

	/** @brief 智能笔拥有者 */
	int ownerId;

	/** @brief 智能笔按下区域 */
	int sectionId;

	/** @brief 智能笔按下书号 */
	int noteId;

	/** @brief 智能笔按下页号*/
	int pageId;

	/** @brief 智能笔按下横坐标整数部分 */
	int x;

	/** @brief 智能笔按下纵坐标整数部分 */
	int y;

	/** @brief 智能笔按下横坐标小数部分 */
	int fx;

	/** @brief 智能笔按下纵坐标小数部分 */
	int fy;

	/** @brief 智能笔按下压力值 */
	int force;

	/** @brief 坐标点颜色 */
	int color ;

	/** @brief 坐标点时间 */
	unsigned int timeLong ;

	/** @brief 坐标的角度 */
	int angle;

	/** @brief 坐标点操作类型 */
	DotType type;

	/** @brief 智能笔按下横坐标*/
	float ab_x;

	/** @brief 智能笔按下纵坐标 */
	float ab_y;
}Dot;


/**
*@brief onHIDGetReady 智能笔蓝牙狗连接状态回调函数
*@param[in] handle 智能笔句柄
*@param[in] bReady 智能笔蓝牙狗当前连接状态
*@return 无
*@notes 该回调只适用使用蓝牙狗连接智能笔
*/
typedef void onHIDGetReady(PENHANDLE handle, bool bReady);//获取蓝牙狗是否连接


/**
*@brief  InitCallBackHIDGetReady 注册智能笔蓝牙狗连接状态回调函数
*@param[in] CallBackFun 能笔蓝牙狗连接状态回调函数
*@return 无
*@notes 该回调只适用使用蓝牙狗连接智能笔
*/
TQLCOMM_API void InitCallBackHIDGetReady(onHIDGetReady CallBackFun);


/**
*@brief onConnectionStatus 智能笔连接状态回调函数
*@param[in] handle 智能笔句柄
*@param[in] bConnected 智能笔当前连接状态
*@return 无
*/
typedef void onConnectionStatus(PENHANDLE handle, bool bConnected);//获取智能笔是否连接


/**
*@brief  InitCallBackConnectionStatus 注册智能笔连接状态回调函数
*@param[in] CallBackFun 智能笔连接状态回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackConnectionStatus(onConnectionStatus CallBackFun);


/**
*@brief onGetPenLocalName 智能笔当前设置名称回调函数
*@param[in] handle 智能笔句柄
*@param[in] localName 智能笔当前设置名称
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
typedef void onGetPenLocalName(PENHANDLE handle, char * localName);//获取智能笔名


/**
*@brief  InitCallBackGetPenLocalName 注册智能笔连接状态回调函数
*@param[in] CallBackFun 智能笔当前设置名称回调函数
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
TQLCOMM_API void InitCallBackGetPenLocalName(onGetPenLocalName CallBackFun);


/**
*@brief onGetMacAddress 智能笔蓝牙地址回调函数
*@param[in] handle 智能笔句柄
*@param[in] macAddress 智能笔蓝牙地址
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
typedef void onGetMacAddress(PENHANDLE handle, char * macAddress);//获取蓝牙地址


/**
*@brief  InitCallBackGetMacAddress 注册智能笔蓝牙地址回调函数
*@param[in] CallBackFun 智能笔蓝牙地址回调函数
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
TQLCOMM_API void InitCallBackGetMacAddress(onGetMacAddress CallBackFun);


/**
*@brief onGetBatteryPower 智能笔电量回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔电量
*@return 无
*@notes 该回调只适用使用带有电池的智能笔
*/
typedef void onGetBatteryPower(PENHANDLE handle, short Data);//读取电量


/**
*@brief  InitCallBackGetBatteryPower 注册智能笔电量回调函数
*@param[in] CallBackFun 智能笔电量回调函数
*@return 无
*@notes 该回调只适用使用带有电池的智能笔
*/
TQLCOMM_API void InitCallBackGetBatteryPower(onGetBatteryPower CallBackFun);


/**
*@brief onGetUsedMemory 智能笔lash内存回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔lash内存
*@return 无
*/
typedef void onGetUsedMemory(PENHANDLE handle, short Data);//读取flash内存


/**
*@brief  InitCallBackGetUsedMemory 注册智能笔lash内存回调函数
*@param[in] CallBackFun 智能笔lash内存回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetUsedMemory(onGetUsedMemory CallBackFun);


/**
*@brief onGetFWVersion 智能笔蓝牙固件版本回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔蓝牙固件版本
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
typedef void onGetFWVersion(PENHANDLE handle, char * strData);//获取蓝牙固件版本


/**
*@brief  InitCallBackGetUsedMemory 注册智能笔蓝牙固件版本回调函数
*@param[in] CallBackFun 智能笔蓝牙固件版本回调函数
*@return 无
*@notes 该回调只适用使用蓝牙智能笔
*/
TQLCOMM_API void InitCallBackGetFWVersion(onGetFWVersion CallBackFun);


/**
*@brief onGetMCUFWVersion 智能笔MCU固件版本回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔MCU固件版本
*@return 无
*/
typedef void onGetMCUFWVersion(PENHANDLE handle, char * strData);//获取MCU固件版本


/**
*@brief  InitCallBackGetMCUFWVersion 注册智能笔MCU固件版本回调函数
*@param[in] CallBackFun 智能笔MCU固件版本回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetMCUFWVersion(onGetMCUFWVersion CallBackFun);


/*
*@brief onGetMCUFWVersion 智能笔MCU序列号回调函数
*@param[in] handle 智能笔句柄
*@param[in] strData 智能笔MCU固件版本
*@return 无
*/
typedef void onGetMCUCode(PENHANDLE handle, char * strData);//获取MCU固件版本


/**
*@brief  InitCallBackGetMCUFWVersion 注册智能笔MCU序列号回调函数
*@param[in] CallBackFun 智能笔MCU固件版本回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetMCUCode(onGetMCUCode CallBackFun);


/**
*@brief onGetMCUFWVersion 智能笔笔尖压力是否唤醒智能笔回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 智能笔笔尖压力是否唤醒智能笔
*@return 无
*/
typedef void onGetAutoPowerOnMode(PENHANDLE handle, bool bSetOn);//获取笔尖压力是否唤醒智能笔


/**
*@brief InitCallBackGetAutoPowerOnMode  注册智能笔笔尖压力是否唤醒智能笔回调函数
*@param[in] CallBackFun 智能笔笔尖压力是否唤醒智能笔笔回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetAutoPowerOnMode(onGetAutoPowerOnMode CallBackFun);


/**
*@brief onGetMCUFWVersion 智能笔自动关机时间回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔自动关机时间
*@return 无
*/
typedef void onGetAutoPowerOffTime(PENHANDLE handle, short Data);//获取自动关机时间


/**
*@brief InitCallBackGetAutoPowerOffTime  注册智能笔自动关机时间回调函数
*@param[in] CallBackFun 智能笔自动关机时间回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetAutoPowerOffTime(onGetAutoPowerOffTime CallBackFun);


/**
*@brief onGetBeepStatus 智能笔蜂鸣器是否响动回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 智能笔蜂鸣器是否响动
*@return 无
*/
typedef void onGetBeepStatus(PENHANDLE handle, bool bSetOn);//获取蜂鸣器是否响动


/**
*@brief InitCallBackGetBeepStatus  注册智能笔蜂鸣器是否响动回调函数
*@param[in] CallBackFun 智能笔蜂鸣器是否响动回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetBeepStatus(onGetBeepStatus CallBackFun);


/**
*@brief onGetBeepStatus 智能笔压力敏感度回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔压力敏感度
*@return 无
*/
typedef void onGetSensitivityLevel(PENHANDLE handle, short Data);//获取压力敏感度


/**
*@brief InitCallBackGetSensitivityLevel  注册智能笔压力敏感度回调函数
*@param[in] CallBackFun 智能笔压力敏感度回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetSensitivityLevel(onGetSensitivityLevel CallBackFun);


/**
*@brief onGetPenColor 智能笔led当前颜色回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔led当前颜色
*@return 无
*/
typedef void onGetPenColor(PENHANDLE handle, short Data);//获取智能笔led当前颜色


/**
*@brief InitCallBackGetPenColor  注册智能笔led当前颜色回调函数
*@param[in] CallBackFun 智能笔led当前颜色回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetPenColor(onGetPenColor CallBackFun);


/**
*@brief onGetRTC 智能笔RTC时间回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔RTC时间
*@return 无
*/
typedef void onGetRTC(PENHANDLE handle, unsigned long Data);//获取RTC时间


/**
*@brief InitCallBackGetRTC  注册智能笔RTC时间回调函数
*@param[in] CallBackFun 智能笔RTC时间回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetRTC(onGetRTC CallBackFun);


/**
*@brief onGetOfflineDataNo 智能笔离线数据量回调函数
*@param[in] handle 智能笔句柄
*@param[in] Data 智能笔离线数据量
*@return 无
*/
typedef void onGetOfflineDataNo(PENHANDLE handle, int Data);//获取离线数据量


/**
*@brief InitCallBackGetOfflineDataNo  注册智能笔离线数据量回调函数
*@param[in] CallBackFun 智能笔离线数据量回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetOfflineDataNo(onGetOfflineDataNo CallBackFun);


/**
*@brief onGetPressureCalibrationData 智能笔压力矫正值回调函数
*@param[in] handle 智能笔句柄
*@param[in] LData 智能笔压力20g矫正值
*@param[in] HData 智能笔压力300g矫正值
*@return 无
*/
typedef void onGetPressureCalibrationData(PENHANDLE handle, int LData, int HData);//读取压力矫正值


/**
*@brief InitCallBackGetPressureCalibrationData  注册智能笔压力矫正值回调函数
*@param[in] CallBackFun 智能笔压力矫正值回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetPressureCalibrationData(onGetPressureCalibrationData CallBackFun);


/**
*@brief onGetCustomerID 智能笔Customer ID回调函数
*@param[in] handle 智能笔句柄
*@param[in] ID1 智能笔Customer ID1值
*@param[in] ID2 智能笔Customer ID2值
*@return 无
*/
typedef void onGetCustomerID(PENHANDLE handle, int ID1, int ID2);//读取Customer ID


/**
*@brief InitCallBackGetCustomerID  注册智能笔Customer ID回调函数
*@param[in] CallBackFun 智能笔Customer ID回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetCustomerID(onGetCustomerID CallBackFun);


/*

*@notes 该方法目前暂停使用*/
typedef void onGetElementCode(PENHANDLE handle, int OID, int SID, int Size);//获取码点数据格式
TQLCOMM_API void InitCallBackGetElementCode(onGetElementCode CallBackFun);


/**
*@brief onGetCustomerID 智能笔OID4码点数据格式回调函数
*@param[in] handle 智能笔句柄
*@param[in] index OID4码点数据格式
*@return 无
*/
typedef void onGetOID4ElementCode(PENHANDLE handle, long index);//获取OID4码点数据格式


/**
*@brief InitCallBackGetOID4ElementCode 注册智能笔OID4码点数据格式回调函数
*@param[in] CallBackFun 智能笔OID4码点数据格式回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetOID4ElementCode(onGetOID4ElementCode CallBackFun);


/**
*@brief onGetOIDType 智能笔码点类型回调函数
*@param[in] handle 智能笔句柄
*@param[in] oType 码点类型
*@return 无
*/
typedef void onGetOIDType(PENHANDLE handle, int oType);//获取码点类型


/**
*@brief InitCallBackGetOIDType 注册 智能笔码点类型回调函数
*@param[in] CallBackFun  智能笔码点类型回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackGetOIDType(onGetOIDType CallBackFun);


/**
*@brief onStartDownloadOfflineData 智能笔启动离线数据是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bStart 启动离线数据是否成功
*@return 无
*/
typedef void onStartDownloadOfflineData(PENHANDLE handle, bool bStart);//启动离线数据是否成功


/**
*@brief InitCallBackStartDownloadOfflineData 注册智能笔启动离线数据是否成功回调函数
*@param[in] CallBackFun  智能笔码点类型回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackStartDownloadOfflineData(onStartDownloadOfflineData CallBackFun);


/**
*@brief onStopDownloadOfflineData 智能笔停止离线数据是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bStart 停止离线数据是否成功
*@return 无
*/
typedef void onStopDownloadOfflineData(PENHANDLE handle, bool bStart);//停止离线数据是否成功


/**
*@brief InitCallBackStopDownloadOfflineData 注册智能笔停止离线数据是否成功回调函数
*@param[in] CallBackFun  智能笔码点类型回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackStopDownloadOfflineData(onStopDownloadOfflineData CallBackFun);


/**
*@brief onEndOfDownloadOfflineData 智能笔离线数据传输完成回调函数
*@param[in] handle 智能笔句柄
*@param[in] bEnd 离线数据传输完成
*@return 无
*/
typedef void onEndOfDownloadOfflineData(PENHANDLE handle, bool bEnd);//离线数据传输完成



/**
*@brief InitCallBackEndOfDownloadOfflineData 注册智能笔离线数据传输完成回调函数
*@param[in] CallBackFun  智能笔离线数据传输完成回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackEndOfDownloadOfflineData(onEndOfDownloadOfflineData CallBackFun);


/**
*@brief onConfirmReceiveOfflineData 智能笔确定离线数据接收完成回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 确定离线数据接收完成
*@return 无
*/
typedef void onConfirmReceiveOfflineData(PENHANDLE handle, bool bSuccess);//确定离线数据接收完成


/**
*@brief InitCallBackConfirmReceiveOfflineData 注册智能笔确定离线数据接收完成回调函数
*@param[in] CallBackFun  智能笔确定离线数据接收完成回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackConfirmReceiveOfflineData(onConfirmReceiveOfflineData CallBackFun);


/**
*@brief onRemoveOfflineData 智能笔删除离线数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] bRemoved 删除离线数据
*@return 无
*/
typedef void onRemoveOfflineData(PENHANDLE handle, bool bRemoved);//删除离线数据


/**
*@brief InitCallBackRemoveOfflineData 注册智能笔删除离线数据回调函数
*@param[in] CallBackFun  智能笔删除离线数据回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackRemoveOfflineData(onRemoveOfflineData CallBackFun);


/**
*@brief onPauseOfflineData 智能笔暂停离线数据接收回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 暂停离线数据接收
*@return 无
*/
typedef void onPauseOfflineData(PENHANDLE handle, bool bSuccess);//暂停离线数据接收


/**
*@brief InitCallBackPauseOfflineData 注册智能笔暂停离线数据接收回调函数
*@param[in] CallBackFun  智能笔暂停离线数据接收回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackPauseOfflineData(onPauseOfflineData CallBackFun);


/**
*@brief onContinueOfflineData 智能笔继续离线数据接收回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 继续离线数据接收
*@return 无
*/
typedef void onContinueOfflineData(PENHANDLE handle, bool bSuccess);//继续离线数据接收


/**
*@brief InitCallBackContinueOfflineData 注册智能笔继续离线数据接收回调函数
*@param[in] CallBackFun  智能笔继续离线数据接收回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackContinueOfflineData(onContinueOfflineData CallBackFun);


/**
*@brief onSetPenLocalName 智能笔设置智能笔名是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置智能笔名是否成功
*@return 无
*/
typedef void onSetPenLocalName(PENHANDLE handle, bool bsuccess);//设置智能笔名是否成功


/**
*@brief InitCallBackSetPenLocalName 注册智能笔设置智能笔名是否成功回调函数
*@param[in] CallBackFun  智能笔设置智能笔名是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetPenLocalName(onSetPenLocalName CallBackFun);


/**
*@brief onSetAutoPowerOnMode 智能笔设置笔尖压力是否唤醒智能笔是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置笔尖压力是否唤醒智能笔是否成功
*@return 无
*/
typedef void onSetAutoPowerOnMode(PENHANDLE handle, bool bsuccess);//设置笔尖压力是否唤醒智能笔是否成功


/**
*@brief InitCallBackSetAutoPowerOnMode 注册智能笔设置笔尖压力是否唤醒智能笔是否成功回调函数
*@param[in] CallBackFun  智能笔设置笔尖压力是否唤醒智能笔是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetAutoPowerOnMode(onSetAutoPowerOnMode CallBackFun);


/**
*@brief onSetAutoPowerOffTime 智能笔设置自动关机时间是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置自动关机时间是否成功
*@return 无
*/
typedef void onSetAutoPowerOffTime(PENHANDLE handle, bool bsuccess);//设置自动关机时间是否成功


/**
*@brief InitCallBackSetAutoPowerOffTime 注册智能笔设置自动关机时间是否成功回调函数
*@param[in] CallBackFun  智能笔设置自动关机时间是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetAutoPowerOffTime(onSetAutoPowerOffTime CallBackFun);


/**
*@brief onSetBeepStatus 智能笔设置蜂鸣器是否响动是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置蜂鸣器是否响动是否成功
*@return 无
*/
typedef void onSetBeepStatus(PENHANDLE handle, bool bsuccess);//设置蜂鸣器是否响动是否成功


/**
*@brief InitCallBackSetBeepStatus 注册智能笔设置蜂鸣器是否响动是否成功回调函数
*@param[in] CallBackFun  智能笔设置蜂鸣器是否响动是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetBeepStatus(onSetBeepStatus CallBackFun);


/**
*@brief onSetSensitivityLevel 智能笔设置压力敏感度是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置压力敏感度是否成功
*@return 无
*/
typedef void onSetSensitivityLevel(PENHANDLE handle, bool bsuccess);//设置压力敏感度是否成功


/**
*@brief InitCallBackSetSensitivityLevel 注册智能笔设置压力敏感度是否成功回调函数
*@param[in] CallBackFun 智能笔设置压力敏感度是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetSensitivityLevel(onSetSensitivityLevel CallBackFun);


/**
*@brief onSetPenColor 智能笔设置智能笔LED颜色是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置智能笔LED颜色是否成功
*@return 无
*/
typedef void onSetPenColor(PENHANDLE handle, bool bsuccess);//设置智能笔LED颜色是否成功


/**
*@brief InitCallBackSetSensitivityLevel 注册智能笔设置智能笔LED颜色是否成功回调函数
*@param[in] CallBackFun 智能笔设置智能笔LED颜色是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetPenColor(onSetPenColor CallBackFun);


/**
*@brief onWriteRTC 智能笔设置RTC时间是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置RTC时间是否成功
*@return 无
*/
typedef void onWriteRTC(PENHANDLE handle, bool bsuccess);//设置RTC时间是否成功


/**
*@brief InitCallBackWriteRTC 注册智能笔设置RTC时间是否成功回调函数
*@param[in] CallBackFun 智能笔设置RTC时间是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackWriteRTC(onWriteRTC CallBackFun);


/**
*@brief onSetElementCode 智能笔设置码点数据格式是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置码点数据格式是否成功
*@return 无
*/
typedef void onSetElementCode(PENHANDLE handle, bool bSuccess);//设置码点数据格式是否成功


/**
*@brief InitCallBackSetElementCode 注册智能笔设置码点数据格式是否成功回调函数
*@param[in] CallBackFun 智能笔设置码点数据格式是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetElementCode(onSetElementCode CallBackFun);


/**
*@brief onSetElementCode 智能笔设置码点类型是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置码点类型是否成功
*@return 无
*/
typedef void onSetOIDType(PENHANDLE handle, bool bSuccess);//设置码点类型是否成功


/**
*@brief InitCallBackSetOIDType 注册智能笔设置码点类型是否成功回调函数
*@param[in] CallBackFun 智能笔设设置码点类型是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetOIDType(onSetOIDType CallBackFun);


/**
*@brief onSetCustomerID 智能笔设置Customer ID是否成功回调函数
*@param[in] handle 智能笔句柄
*@param[in] bSuccess 设置Customer ID是否成功
*@return 无
*/
typedef void onSetCustomerID(PENHANDLE handle, bool bsuccess);//设置Customer ID是否成功


/**
*@brief InitCallBackSetOIDType 注册智能笔设置Customer ID是否成功回调函数
*@param[in] CallBackFun 智能笔设置Customer ID是否成功回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackSetCustomerID(onSetCustomerID CallBackFun);


/**
*@brief onReceiveDot 智能笔实时笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 实时笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
typedef void onReceiveDot(PENHANDLE handle, Dot* dot, int count);//实时笔迹数据


/**
*@brief InitCallBackReceiveDot 注册智能笔实时笔迹数据回调函数
*@param[in] CallBackFun 智能笔实时笔迹数据回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackReceiveDot(onReceiveDot CallBackFun);


/**
*@brief onReceiveOriginalDot 智能笔过滤前实时笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 过滤前实时笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
typedef void onReceiveOriginalDot(PENHANDLE handle, Dot* dot, int count);//过滤前实时笔迹数据


/**
*@brief InitCallBackReceiveOriginalDot 注册智能笔实时笔迹数据回调函数
*@param[in] CallBackFun 智能笔实时笔迹数据回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackReceiveOriginalDot(onReceiveOriginalDot CallBackFun);


/**
*@brief onReceiveOfflineData 智能笔离线笔迹数据回调函数
*@param[in] handle 智能笔句柄
*@param[in] dot 离线笔迹数据
*@param[in] count 当前Count值
*@return 无
*/
typedef void onReceiveOfflineData(PENHANDLE handle, Dot* dot, int count);//离线笔迹数据


/**
*@brief InitCallBackReceiveOfflineData 注册智能笔离线笔迹数据回调函数
*@param[in] CallBackFun 智能笔离线笔迹数据回调函数
*@return 无
*/
TQLCOMM_API void InitCallBackReceiveOfflineData(onReceiveOfflineData CallBackFun);


typedef void onUpDown(PENHANDLE handle, bool isUp, int count);
TQLCOMM_API void InitCallBackUpDown(onUpDown CallBackFun);


/**
*@brief Init 智能笔智能笔初始化
*@return  int 智能笔句柄
*/
TQLCOMM_API PENHANDLE Init();

/**
*@brief Close 关闭打开的智能笔并释放资源
*@return  int 智能笔句柄
*/
TQLCOMM_API bool Close(PENHANDLE handle);

/**
*@brief handleInit 智能笔智能笔初始化
*@handle  int 智能笔句柄
*/
TQLCOMM_API void handleInit(PENHANDLE handle);

/**
*@brief handleClose 关闭打开的智能笔并释放资源
*@return  int 智能笔句柄
*/
TQLCOMM_API bool handleClose(PENHANDLE handle);

/**
*@brief StartCallBack 启动回调函数
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool StartCallBack(PENHANDLE handle);




/**
*@brief ReqHIDStatus 获取蓝牙狗连接状态
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*@notes 该回调只适用使用带有电池的智能笔
*/
TQLCOMM_API bool ReqHIDStatus(PENHANDLE handle);


/**
*@brief ReqConnectionStatus 获取智能笔连接状态
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool ReqConnectionStatus(PENHANDLE handle);


/**
*@brief ConnectNewDevice 连接新的一支笔
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool ConnectNewDevice(PENHANDLE handle);


/**
*@brief ConnectNewDevice 断开智能笔
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool DisconnectDevice(PENHANDLE handle);


/**
*@brief GetPenLocalName 获取智能笔笔名
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool GetPenLocalName(PENHANDLE handle);


/**
*@brief SetPenLocalName 设置智能笔笔名
*@param[in] handle 智能笔句柄
*@param[in] newLocalName 智能笔笔名
*@param[in] Len 智能笔笔名长度
*@return bool成功或失败
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool SetPenLocalName(PENHANDLE handle, char * newLocalName, int Len);


/**
*@brief GetMacAddress 获取智能笔Mac地址
*@param[in] handle 智能笔句柄
*@return 无
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool GetMacAddress(PENHANDLE handle);


/**
*@brief GetFWVersion 获取智能笔Mac版本号
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*@notes 该回调只适用蓝牙智能笔
*/
TQLCOMM_API bool GetFWVersion(PENHANDLE handle);


/**
*@brief GetMCUFWVersion 获取智能笔mcu固件版本号
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetMCUFWVersion(PENHANDLE handle);

/**
*@brief SetMCUCode 获取智能笔mcu序列号
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetMCUCode(PENHANDLE handle);

/**
*@brief GetMCUFWVersion 获取智能笔电量
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetBatteryPower(PENHANDLE handle);


/**
*@brief GetMCUFWVersion 获取智能笔使用内存
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetUsedMemory(PENHANDLE handle);


/**
*@brief GetMCUFWVersion 获取智能笔自动关机时间
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetAutoPowerOffTime(PENHANDLE handle);


/**
*@brief GetMCUFWVersion 设置智能笔自动关机时间
*@param[in] handle 智能笔句柄
*@param[in] offtime 自动关机时间
*@return bool成功或失败
*/
TQLCOMM_API bool SetAutoPowerOffTime(PENHANDLE handle, short offtime);


/**
*@brief GetPressureCalibrationData 读取压力矫正值
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetPressureCalibrationData(PENHANDLE handle);


/**
*@brief GetCustomerID 读取CustomerID
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetCustomerID(PENHANDLE handle);


/**
*@brief SetCustomerID 设置CustomerID
*@param[in] handle 智能笔句柄
*@param[in] ID1 CustomerID1
*@param[in] ID2 CustomerID2
*@return bool成功或失败
*/
TQLCOMM_API bool SetCustomerID(PENHANDLE handle, int ID1, int ID2);


/**
*@brief SetCustomerID 获取CustomerID
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetElementCode(PENHANDLE handle);

TQLCOMM_API bool SetElementCode(PENHANDLE handle, int OID, int SID, int Size);


/**
*@brief GetAutoPowerOnMode 获取笔尖压力是否唤醒笔
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetAutoPowerOnMode(PENHANDLE handle);


/**
*@brief SetAutoPowerOnMode 设置笔尖压力是否唤醒笔
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 是否唤醒笔
*@return bool成功或失败
*/
TQLCOMM_API bool SetAutoPowerOnMode(PENHANDLE handle, bool bSetOn);


/**
*@brief GetBeepStatus 获取蜂鸣器是否响动
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetBeepStatus(PENHANDLE handle);


/**
*@brief SetBeepStatus 设置蜂鸣器是否响动
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 是否唤响动
*@return bool成功或失败
*/
TQLCOMM_API bool SetBeepStatus(PENHANDLE handle, bool bSetOn);


/**
*@brief GetColorConfigStatus 获取笔端切换笔迹颜色功能是否开启
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetColorConfigStatus(PENHANDLE handle);


/**
*@brief SetColorConfigStatus 设置笔端切换笔迹颜色功能是否开启
*@param[in] handle 智能笔句柄
*@param[in] bSetOn 是否开启
*@return bool成功或失败
*/
TQLCOMM_API bool SetColorConfigStatus(PENHANDLE handle, bool bSetOn);


/**
*@brief GetSensitivityLevel 获取压力敏感度
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetSensitivityLevel(PENHANDLE handle);


/**
*@brief SetSensitivityLevel 设置压力敏感度
*@param[in] handle 智能笔句柄
*@param[in] level 敏感度0-4
*@return bool成功或失败
*/
TQLCOMM_API bool SetSensitivityLevel(PENHANDLE handle, short level);


/**
*@brief GetPenColor 获取智能笔LED灯颜色
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetPenColor(PENHANDLE handle);


/**
*@brief SetPenColor 设置智能笔LED灯颜色
*@param[in] handle 智能笔句柄
*@param[in] ncolor LED灯颜色
*@return bool成功或失败
*/
TQLCOMM_API bool SetPenColor(PENHANDLE handle, short ncolor);



/**
*@brief ConfirmSelectedPenColor 返回收到按键切换APP端笔迹颜
*@param[in] handle 智能笔句柄
*@param[in] result 是否收到
*@return bool成功或失败
*/
TQLCOMM_API bool ConfirmSelectedPenColor(PENHANDLE handle, bool result);


/**
*@brief GetRTC 获取智能笔RTC
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetRTC(PENHANDLE handle);


/**
*@brief WriteRTC 设置智能笔RTC
*@param[in] handle 智能笔句柄
*@param[in] nRTC RTC时间
*@return bool成功或失败
*/
TQLCOMM_API bool WriteRTC(PENHANDLE handle, unsigned long nRTC);


/**
*@brief GetSmartPenType 读取当前笔的型号
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetSmartPenType(PENHANDLE handle);


/**
*@brief GetOfflineDataNo 获取离线数据量
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool GetOfflineDataNo(PENHANDLE handle);


/**
*@brief StartDownloadOfflineData 开始离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool StartDownloadOfflineData(PENHANDLE handle);


/**
*@brief StopDownloadOfflineData 结束离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool StopDownloadOfflineData(PENHANDLE handle);


/**
*@brief PauseDownloadOfflineData 暂停离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool PauseDownloadOfflineData(PENHANDLE handle);


/**
*@brief ContinueDownloadOfflineData 继续离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool ContinueDownloadOfflineData(PENHANDLE handle);


/**
*@brief ConfirmReceiveOfflineData 完成离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool ConfirmReceiveOfflineData(PENHANDLE handle, bool bSuccess);


/**
*@brief RemoveOfflineData 删除离线数据
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool RemoveOfflineData(PENHANDLE handle);


/**
*@brief ReadOIDType 获取码点类型
*@param[in] handle 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool ReadOIDType(PENHANDLE handle);


/**
*@brief SetOIDType 设置码点类型
*@param[in] handle 智能笔句柄
*@param[in] oType 码点类型
*@return bool成功或失败
*/
TQLCOMM_API bool SetOIDType(PENHANDLE handle, int oType);



/**
*@brief SetReceiveSrcData 发送原始数据进行解析
*@param[in] handle 智能笔句柄
*@param[in] Srcdata 码点类型
*@param[in] DataLen 智能笔句柄
*@return bool成功或失败
*/
TQLCOMM_API bool SetReceiveSrcData(PENHANDLE handle, char * Srcdata, int DataLen);

