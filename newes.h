#ifndef NEWES_H
#define NEWES_H

#include <QApplication>
#include <QLabel>
#include <QFile>
#include <QHBoxLayout>
#include <QVBoxLayout>


class Newes : public QLabel
{
    Q_OBJECT

public:
        Newes(QString name, QString heading, QString path, QWidget *parent = 0);
        ~Newes();
};

#endif // NEWES_H
