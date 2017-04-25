#ifndef CONTENT_H
#define CONTENT_H

#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include <QFile>

#include "newes.h"
#include "database.h"

class Newes;

class Content : public QLabel
{
    Q_OBJECT

public:
        Content(QWidget *parent = 0);
        ~Content();

public:
        void Layout();
        void searchResult(const QString &value);
        void Refresh();

private:
        Database *database;
        QVector<QVector<QString> > data;
        QVBoxLayout *layout;

private:
        void remove(QLayout *layout);


};

#endif // CONTENT_H
