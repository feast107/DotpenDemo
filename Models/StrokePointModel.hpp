#ifndef STROKEPOINTMODEL_H
#define STROKEPOINTMODEL_H
#include "Component/Helper.hpp"
#include "ResponseModel.hpp"

class StrokePointModel : public ModelBase
{
    public:
        StrokePointModel(){}
        StrokePointModel(int x,int y){
            this->x=x;
            this->y=y;
        }
        ~StrokePointModel(){}

        int x;
        int y;

        void FromJson(QJsonObject json)override
        {

            if (json.contains(STRING_MODEL_X))
            {
                QJsonValue value = json.value(STRING_MODEL_X);
                this->x = value.toInt();
            }

            if (json.contains(STRING_MODEL_Y))
            {
                QJsonValue value = json.value(STRING_MODEL_Y);
                this->y = value.toInt();
            }


        }
        QJsonObject ToJson()
        {
            QJsonObject ret;
            ret.insert(STRING_MODEL_X,x);
            ret.insert(STRING_MODEL_Y,y);

            return ret;
        }

};
#endif // STROKEPOINTMODEL_H
