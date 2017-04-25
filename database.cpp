#include "database.h"

Database::Database()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library");
    db.setUserName("Diana");
    db.setPassword("0000");
    db.setHostName("localhost");

    if(!db.open())
        qDebug() << "Can not open db manager";

    query = new QSqlQuery(db);
}

Database::~Database()
{

}

void Database::CreateTable()
{
    QString table = "CREATE TABLE public("
                                             "Name VARCHAR(20),"
                                             "Heading VARCHAR(20),"
                                             "Logo VARCHAR(20)"
                                             ");";
    if(!query->exec(table))
        qDebug() << "Unable to create table!";
}

void Database::Inputing(const QString &name, const QString &heading, const QString &logo)
{
    QString tamplate = "INSERT INTO public(Name, Heading, Logo)"
                       "VALUES('%1', '%2', '%3');";

    QString command = tamplate.arg(name)
                        .arg(heading)
                        .arg(logo);

    if(!query->exec(command))
        qDebug() << "Error with inputing data!";
}

QVector<QVector<QString> > &Database::Reading()
{
    data.clear();

    if(!query->exec("SELECT * FROM public;"))
        qDebug() << "Unable to read data!";

    while(query->next())
    {
        QVector<QString> row;

        for(int i=0; i<4; i++)
            row.push_back(query->value(i).toString());

        data.push_back(row);
    }

    return data;
}

QVector<QVector<QString> > &Database::Searching(const QString &value)
{
    data.clear();

    if(!query->exec("SELECT * FROM public WHERE Name = \"" + value + "\";"))
        qDebug() << "Unable to search data!";

    while(query->next())
    {
        QVector<QString> row;

        for(int i=0; i<4; i++)
            row.push_back(query->value(i).toString());

        data.push_back(row);
    }

    return data;
}

