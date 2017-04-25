#include "content.h"

Content::Content(QWidget *parent) : QLabel(parent)
{
    bool exist = false;
    if(QFile::exists("library")) exist = true;
    database = new Database;
    if(!exist) database->CreateTable();

    layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    Layout();
    this->setLayout(layout);
}

Content::~Content()
{

}

void Content::Layout()
{
    this->setStyleSheet("background: rgb(161, 195, 94);");
    data = database->Reading();

    Newes *newes;
    for(int i=0; i<data.size(); i++)
    {
        newes = new Newes(data[i][0], data[i][1], data[i][2]);
        newes->setMinimumHeight(350);

        layout->addWidget(newes);
        this->resize(350, (i+1)*350 + 50);
    }
}

void Content::searchResult(const QString &value)
{
    delete database;

    bool exist = false;
    if(QFile::exists("library")) exist = true;
    database = new Database;
    if(!exist) database->CreateTable();

    remove(layout);

    data = database->Searching(value);
    Newes *newes;
    for(int i=0; i<data.size(); i++)
    {
        newes = new Newes(data[i][0], data[i][1], data[i][2]);
        newes->setMinimumHeight(350);

        layout->addWidget(newes);
        this->resize(350, (i+1)*350 + 50);
    }
}

void Content::Refresh()
{
    delete database;

    bool exist = false;
    if(QFile::exists("library")) exist = true;
    database = new Database;
    if(!exist) database->CreateTable();

    remove(layout);
    Layout();
}

void Content::remove(QLayout *layout)
{
    QLayoutItem* child;
    while(layout->count() != 0)
    {
        child = layout->takeAt(0);

        if(child->layout() != 0)
        {
            remove(child->layout());
        }

        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}
