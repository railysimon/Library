#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QVector>

class Database
{
public:
        Database();
        ~Database();

        void CreateTable();
        void Inputing(const QString &name, const QString &heading, const QString &logo);
        QVector<QVector<QString> > &Reading();
        QVector<QVector<QString> > &Searching(const QString &value);

private:
        QSqlQuery *query;
        QVector<QVector <QString> > data;
};

#endif // DATABASE_H
