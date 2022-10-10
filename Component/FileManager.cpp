#include "FileManager.h"
#include "QtTool_global.h"
#include "Helper.hpp"
#include "QJsonDocument"


File FileManager::Add()
{
    QList<File> fs = GetFiles();
    int maximun = 1;
    for(auto f : fs){
        int num = f.NameWithoutExtension().toInt();
        if(maximun <= num){
            maximun = num+1;
        }
    }
    File f(Path::Combine({Path::CurrentDirectory(), "Record",QString::number(maximun)}));
    f.Create();
    return f;
}

void FileManager::Store(File f, QList<StrokeModel*> *strokes)
{
    if(f.Exist()){
        QString content = "";
        bool empty = f.Length()==0;
        for(StrokeModel* stroke : *strokes)
        {
            QString serial =  QString(QJsonDocument(stroke->ToJson()).toJson(QJsonDocument::Compact));
            if(content=="" && empty){
                content += serial;
            }else{
                content += ',' + serial;
            }
        }

        f.AppendText(content);
    }

}

void FileManager::Store(SignForm::Page *page)
{
    if(page->file.Exist() && page->storedIndex<page->strokeList->length()){
        QString content = "";
        bool empty = page->file.Length()==0;
        for(;page->storedIndex < page->strokeList->length();(page->storedIndex)++)
        {
            QString serial =  QString(QJsonDocument(page->strokeList->at(page->storedIndex)->ToJson()).toJson(QJsonDocument::Compact));
            if(content=="" && empty){
                content += serial;
            }else{
                content += ',' + serial;
            }
        }
        page->file.AppendText(content);
    }
}

QList<File> FileManager::GetFiles()
{
    return Directory(Path::Combine({Path::CurrentDirectory(), "Record"})).GetFiles();
}

QList<StrokeModel *> *FileManager::Load(File  f)
{
    QList<StrokeModel*>* ret = new QList<StrokeModel*>();
    if(f.Exist()){
        QJsonParseError jsonError;
        QString text =  f.ReadText();
        if(!text.isEmpty()){
            text =  '[' + text+ ']';
            QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8(),&jsonError);
            if (jsonError.error != QJsonParseError::NoError){
                QString errdata = QString(jsonError.errorString().toUtf8().constData());
                qDebug() << errdata;
                f.Delete();
            }
            QJsonArray arr = doc.array();//QJsonDocument转QJsonObject
            for(auto obj : arr){
                StrokeModel* model = new StrokeModel();
                model->FromJson(obj.toObject());
                ret->append(model);
            }
        }
    }
    return ret;
}

void FileManager::Delete(File f)
{
    if(f.Exist()){
        f.Delete();
    }
}

void FileManager::Clean(File f)
{
    if(f.Exist()){
        f.WriteText("");
    }
}
