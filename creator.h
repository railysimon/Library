#ifndef CREATOR_H
#define CREATOR_H

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>

#include "database.h"

class Database;

class Creator : public QDialog
{
    Q_OBJECT

public:
        Creator(QWidget *parent = 0);
        ~Creator();

private:
         void Layout();
         QLineEdit *edit(QString title);
         QPushButton *button(QPixmap icon, int btn_width);

private:
         QPixmap logo;
         QLineEdit *name, *heading;
         QTextEdit *review;
         QLabel *logo_viewer;
         QPushButton *add, *open;

         Database *database;
         QString path;

private slots:
            void ButtonClick();
};

#endif // CREATOR_H
