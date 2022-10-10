#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include "Models/StrokeModel.hpp"
#include <QList>
#include <Form/SignForm.h>
class FileManager
{   
    public:
        static File Add();
        static void Store(File file, QList<StrokeModel*>* strokes);
        static void Store(SignForm::Page* page);
        static QList<File> GetFiles();
        static QList<StrokeModel*>* Load(File file);
        static void Delete(File f);
        static void Clean(File f);
};

#endif // FILEMANAGER_H
