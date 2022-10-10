#ifndef STRINGS_H
#define STRINGS_H

#define STRING_TITLE "纸面签批"

#define STRING_PEN_INVALID "当前笔无效"
#define STRING_PEN_VALID "当前笔有效"
#define STRING_PEN_CONNECT "笔已连接"
#define STRING_PEN_DISCONNECT "笔已断开"
#define STRING_PEN_NOTCONNECT "当前没有笔连接"

#define STRING_DOT_INVALID "当前点阵无效"
#define STRING_DOT_NOTCORRESPOND "与当前点阵不符"
#define STRING_AREA_OUTSIDE "请在区域内书写"

#define STRING_TASK_HAD "当前有任务正在进行"
#define STRING_TASK_404 "没有该任务"


#define STRING_BROWSER_UNCONNECT "未连接到浏览器"
#define STRING_BROWSER_CONNECT "已连接到浏览器"
#define STRING_BROWSER_DISCONNET "浏览器断开"
#define STRING_BROWSER_REJECT "阻止了一个新的连接"

#define STRING_ALERT_SUBMIT_SUCCESS "提交成功！"
#define STRING_ALERT_SUBMIT_FAILED "提交失败，请检查网络"

#define PUBLISH
#ifndef PUBLISH
#define STRING_SERVER_ADDRESS QString("http://47.93.86.37:8233/")
#else
#define STRING_SERVER_ADDRESS QString("http://222.74.9.114:2003/")
#endif

#define STRING_TEST_ADDRESS QString("http://192.168.101.62:9001/")
#define STRING_API_TEST_POST QString("demoservice/task/test")
#define STRING_API_PEN_FIND QString("api/pen/find")
#define STRING_API_FORM_FIND QString("api/form/find")
#define STRING_API_TASK_FIND QString("api/task/find")
#define STRING_API_FORM_PICTURE QString("form/")
#define STRING_API_TASK_SIGN QString("api/task/sign")
#define STRING_API_TASK_STROKE QString("api/task/stroke")

#define STRING_API_STROKE_EXTEN QString(".stroke.txt")


#define STRING_MODEL_DATA "data"
#define STRING_MODEL_CODE "code"
#define STRING_MODEL_MSG "msg"

#define STRING_MODEL_AREA "area"
#define STRING_MODEL_FORM "form"
#define STRING_MODEL_TASK "task"

#define STRING_MODEL_USER "user"
#define STRING_MODEL_DATE "date"

#define STRING_MODEL_USERNAME "userName"
#define STRING_MODEL_USERNAME_L "username"
#define STRING_MODEL_ID "id"
#define STRING_MODEL_FORMID "formId"
#define STRING_MODEL_FORMNAME "formName"
#define STRING_MODEL_FORMCODE "formCode"

#define STRING_MODEL_AREANAME "areaName"
#define STRING_MODEL_AREADESC "areaDesc"
#define STRING_MODEL_AREAVALUE "areaValue"

#define STRING_MODEL_X "x"
#define STRING_MODEL_Y "y"
#define STRING_MODEL_W "w"
#define STRING_MODEL_H "h"

#define STRING_MODEL_CONTENTX "contentX"
#define STRING_MODEL_CONTENTY "contentY"
#define STRING_MODEL_CONTENTW "contentW"
#define STRING_MODEL_CONTENTH "contentH"

#define STRING_MODEL_TIMESTAMP "timestamp"
#define STRING_MODEL_ORGANIZATION "organization"
#define STRING_MODEL_PAGENUM "pageNum"
#define STRING_MODEL_PAGECOUNT "pageCount"
#define STRING_MODEL_PAGEHEIGHT "pageHeight"
#define STRING_MODEL_PAGEWIDTH "pageWidth"
#define STRING_MODEL_PAGEADDRESS "pageAddress"
#define STRING_MODEL_PAGEADDRESSLIST "pageAddressList"
#define STRING_MODEL_ITEMDATALIST "itemDataList"
#define STRING_MODEL_FORMITEMLIST "formItemList"
#define STRING_MODEL_COMMONPAGEADDRESS "commonPageAddress"
#define STRING_MODEL_TASKSTARTPAGEADDRESS "taskStartPageAddress"



#define STRING_MODEL_ACCOUNT "account"
#define STRING_MODEL_ISDELETE "isDelete"
#define STRING_MODEL_ISENABLE "isEnable"
#define STRING_MODEL_PENSERIAL "penSerial"

#define STIRNG_MODEL_SIGNTIME "SignTime"
#define STRING_MODEL_PS "pS"
#define STRING_MODEL_UN "uN"
#define STRING_MODEL_C "c"
#define STRING_MODEL_T "t"
#define STRING_MODEL_D "d"
#define STRING_MODEL_N "n"
#define STRING_MODEL_X1 "x1"
#define STRING_MODEL_Y1 "y1"
#define STRING_MODEL_P "p"
#define STRING_MODEL_ST "sT"

#define STRING_AREA_OPINION3 "OPINION3"
#define STRING_AREA_JOINTSIGN "JOINTSIGN"
#define STRING_AREA_REMARKS "REMARKS"

#define STRING_JSON_HANDLE "handle"
#define STRING_JSON_IDENTIFIER "id"
#define STRING_JSON_IMAGEAREA "imageArea"
#define STRING_JSON_BASE64 "base64"
#define STRING_JSON_BASE64HEAD "data:image/png;base64,"
#define STRING_JSON_TASKID "taskId"
#define STRING_JSON_STROKELIST "strokeList"
#endif // STRINGS_H
