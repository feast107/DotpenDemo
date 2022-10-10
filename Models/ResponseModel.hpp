#ifndef RESPONSEMODEL_H
#define RESPONSEMODEL_H
#include <Qt_Heads.h>
#include "Configuration/Strings.h"

class ModelBase{
    public:
        virtual void FromJson(QJsonObject){}
        virtual void FromArray(QJsonArray){}
};
class ResponseModel
{
    public:
        ResponseModel(){}
        int code = 0 ;
        ModelBase* data;
        QString msg;
        static ResponseModel FromJson(QJsonObject json, ModelBase* base)
        {
            ResponseModel model;
            if (json.contains(STRING_MODEL_CODE))
            {  // 包含指定的 key
                QJsonValue value = json.value(STRING_MODEL_CODE);  // 获取指定 key 对应的 value
                model.code = value.toInt();

            }
            if (json.contains(STRING_MODEL_DATA))
            {
                QJsonValue value = json.value(STRING_MODEL_DATA);
                if (value.isObject())
                {
                    model.data = base;
                    model.data->FromJson(value.toObject());
                }
            }
            if (json.contains(STRING_MODEL_MSG))
            {
                QJsonValue value = json.value(STRING_MODEL_MSG);
                if (value.isString())
                {
                    model.msg = value.toString();
                }
            }
            return model;
        }

        static ResponseModel FromJson(QByteArray json, ModelBase* base)
        {
            QJsonDocument document = QJsonDocument::fromJson(json);
            return FromJson(document.object(),base);
        }

        static ResponseModel FromArray(QJsonObject json, ModelBase* base)
        {
            ResponseModel model;
            if (json.contains(STRING_MODEL_CODE))
            {  // 包含指定的 key
                QJsonValue value = json.value(STRING_MODEL_CODE);  // 获取指定 key 对应的 value
                model.code = value.toInt();

            }
            if (json.contains(STRING_MODEL_DATA))
            {
                QJsonValue value = json.value(STRING_MODEL_DATA);
                if (value.isArray())
                {
                    model.data = base;
                    model.data->FromArray(value.toArray());
                }
            }
            if (json.contains(STRING_MODEL_MSG))
            {
                QJsonValue value = json.value(STRING_MODEL_MSG);
                if (value.isString())
                {
                    model.msg = value.toString();
                }
            }
            return model;
        }

        static ResponseModel FromArray(QByteArray json, ModelBase* base)
        {
            QJsonDocument document = QJsonDocument::fromJson(json);
            return FromArray(document.object(),base);
        }
};
#define JSON ResponseModel::FromJson
#define ARRAY ResponseModel::FromArray
#endif // RESPONSEMODEL_H
