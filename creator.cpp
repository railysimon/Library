#include "creator.h"

Creator::Creator(QWidget *parent) : QDialog(parent), logo(QApplication::applicationDirPath() + "/default")
{
    logo = logo.scaled(QSize(200, 200), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    path = QApplication::applicationDirPath() + "/default";

    Layout();

    bool exist = false;
    if(QFile::exists("library")) exist = true;
    database = new Database;
    if(!exist) database->CreateTable();
}

Creator::~Creator()
{

}

void Creator::Layout()
{
    QHBoxLayout *top_layer = new QHBoxLayout;
    top_layer->setAlignment(Qt::AlignCenter);

    logo_viewer = new QLabel;
    logo_viewer->setPixmap(logo);
    logo_viewer->setFrameStyle(QFrame::Panel | QFrame::Raised);
    top_layer->addWidget(logo_viewer);

    name = edit("name");
    heading = edit("heading");

    review = new QTextEdit;
    review->setStyleSheet("background: rgb(245, 245, 245); border: 2px solid green;");
    review->setFont(QFont("Ubuntu", 10, QFont::Bold));

    open = button(QPixmap("open"), 40);
    add = button(QPixmap("add"), 60);

    QHBoxLayout *bottom_layer = new QHBoxLayout;
    bottom_layer->addWidget(open);
    bottom_layer->addWidget(add);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(top_layer);
    layout->addWidget(name);
    layout->addWidget(heading);
    layout->addWidget(review);
    layout->addLayout(bottom_layer);

    this->setLayout(layout);
    this->setFixedSize(350, 450);
    this->setStyleSheet("background: rgb(116, 242, 187);");
    this->setWindowTitle("Add new publication");

}

QLineEdit *Creator::edit(QString title)
{
    QLineEdit *line = new QLineEdit(title);
    line->setStyleSheet("background: rgb(245, 245, 245); border: 2px solid green;");
    line->setFont(QFont("Ubuntu", 10, QFont::Bold));

    return line;
}

QPushButton *Creator::button(QPixmap icon, int btn_width)
{
    QPushButton *btn = new QPushButton();
    btn->setCursor(Qt::PointingHandCursor);
    btn->setIconSize(QSize(25, 25));
    btn->setFixedSize(btn_width, 40);
    btn->setStyleSheet("QPushButton:hover { background: rgb(67, 236, 73); }"
                       "QPushButton { background: rgb(114, 197, 228); }");
    btn->setIcon(QIcon(icon));

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(ButtonClick()));

    return btn;

}

void Creator::ButtonClick()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if(btn->width() == 40)
    {
        path = QFileDialog::getOpenFileName(this, "Open...", "", "*.png;; *.jpg;;");
        if(!path.isEmpty())
        {
            logo.load(path);
            logo = logo.scaled(QSize(200, 200), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            logo_viewer->setPixmap(logo);
        }
    }

    if(btn->width() == 60)
    {
        database->Inputing(name->text(), heading->text(), path);

        QFile file(name->text());
        file.open(QIODevice::WriteOnly);

        QByteArray block;
        block.append(review->document()->toPlainText());
        file.write(block);

        file.close();
    }
}
