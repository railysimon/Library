#include "newes.h"

Newes::Newes(QString name, QString heading, QString path, QWidget *parent) : QLabel(parent)
{
    QPixmap pix(path);
    pix = pix.scaled(QSize(200, 200), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QLabel *picture = new QLabel;
    picture->setPixmap(pix);

    QFile file(QApplication::applicationDirPath() + "/" + name);
    file.open(QIODevice::ReadOnly);
    QString text = file.readAll();
    file.close();

    QLabel *title = new QLabel(name);
    title->setFont(QFont("Ubuntu", 16, QFont::Bold));

    QLabel *review = new QLabel(text);
    review->setFont(QFont("Ubuntu", 10, QFont::Cursive));

    QLabel *headline = new QLabel(heading);
    headline->setFont(QFont("Ubuntu", 11, QFont::Bold));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(picture);
    layout->addWidget(title);
    layout->addWidget(review);
    layout->addWidget(headline);

    this->setLayout(layout);
    this->setFrameStyle(QFrame::Box | QFrame::Raised);
}

Newes::~Newes()
{

}
