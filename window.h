#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>

#include "content.h"
#include "creator.h"

class Content;
class Creator;

class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private:
        Content *content;
        QScrollArea *scrollarea;
        Creator *creator;
        QLineEdit *search_line;
        QPushButton *search_btn, *add_btn, *reload_btn;

private:
        void Layout();
        QPushButton *button(QPixmap icon, int size, int btn_size);

private slots:
                void ButtonClick();
};

#endif // WINDOW_H
