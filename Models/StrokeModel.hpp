#ifndef STROKEMODEL_HPP
#define STROKEMODEL_HPP
#include "Component/Helper.hpp"
#include "ResponseModel.hpp"
#include "StrokePointModel.hpp"
class StrokeModel : public ModelBase
{
    public:
        StrokeModel(){}

        ///
        /// \brief 颜色码
        ///
        int c;
        ///
        /// \brief 粗细
        ///
        int t;
        ///
        /// \brief 书写时长
        ///

        int d;
        ///
        /// \brief 页码 pageNum
        ///
        int n;

        ///
        /// \brief 点Path
        ///
        QString p;


        ///
        /// \brief 点集合
        ///
        QList<StrokePointModel> *pointList = new QList<StrokePointModel>();

        void FromJson(QJsonObject json)override
        {

            if (json.contains(STRING_MODEL_C))
            {
                QJsonValue value = json.value(STRING_MODEL_C);
                this->c = value.toInt();
            }
            if (json.contains(STRING_MODEL_T))
            {
                QJsonValue value = json.value(STRING_MODEL_T);
                this->t = value.toInt();
            }
            if (json.contains(STRING_MODEL_D))
            {
                QJsonValue value = json.value(STRING_MODEL_D);
                this->d = value.toInt();
            }
            if (json.contains(STRING_MODEL_N))
            {
                QJsonValue value = json.value(STRING_MODEL_N);
                this->n = value.toInt();
            }

            if (json.contains(STRING_MODEL_P))
            {
                QJsonValue value = json.value(STRING_MODEL_P);
                if (value.isString())
                {
                    this->p = value.toString();
                }
            }

            this->pointList=DeSerializeStroke(p);


        }

        QJsonObject ToJson()
        {
            QJsonObject ret;
            ret.insert(STRING_MODEL_C,c);
            ret.insert(STRING_MODEL_T,t);
            ret.insert(STRING_MODEL_D,d);
            ret.insert(STRING_MODEL_N,n);
            p = SerializeStroke(this->pointList);
            ret.insert(STRING_MODEL_P,p);
            return ret;
        }
};

#endif // STROKEMODEL_HPP
