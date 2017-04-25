#include "window.h"

Window::Window(QWidget *parent): QDialog(parent)
{
    scrollarea = new QScrollArea;
    content = new Content;
    scrollarea->setWidget(content);

    Layout();
}

Window::~Window()
{

}

void Window::Layout()
{
    QHBoxLayout *top_layout = new QHBoxLayout;

    search_line = new QLineEdit;
    search_line->setStyleSheet("background: rgb(245, 245, 245); border: 2px solid green;");
    search_line->setFont(QFont("Ubuntu", 10, QFont::Bold));
    search_btn = button(QPixmap(QApplication::applicationDirPath() + "/search"), 25, 25);
    reload_btn = button(QPixmap(QApplication::applicationDirPath() + "/restart"), 25, 26);

    top_layout->addWidget(search_line);
    top_layout->addWidget(search_btn);
    top_layout->addWidget(reload_btn);

    QHBoxLayout *bottom_layer = new QHBoxLayout;
    bottom_layer->setAlignment(Qt::AlignCenter);
    add_btn = button(QPixmap(QApplication::applicationDirPath() + "/add"), 25, 40);
    bottom_layer->addWidget(add_btn);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(top_layout);
    layout->addWidget(scrollarea);
    layout->addLayout(bottom_layer);
    this->setLayout(layout);
    this->setStyleSheet("background: rgb(86, 87, 88);");
    this->setFixedSize(400, 500);
    this->setWindowTitle("Publication library");
}

QPushButton *Window::button(QPixmap icon, int size, int btn_size)
{
    QPushButton *btn = new QPushButton();
    btn->setCursor(Qt::PointingHandCursor);
    btn->setIconSize(QSize(size, size));
    btn->setFixedSize(btn_size, btn_size);
    btn->setStyleSheet("QPushButton:hover { background: rgb(67, 236, 73); }"
                       "QPushButton { background: rgb(114, 197, 228); }");
    btn->setIcon(QIcon(icon));

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(ButtonClick()));

    return btn;
}

void Window::ButtonClick()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if(btn->width() == 40)
    {
        creator = new Creator(this);
        creator->show();
    }
    if(btn->width() == 26) content->Refresh();
    if(btn->width() == 25) content->searchResult(search_line->text());
}
