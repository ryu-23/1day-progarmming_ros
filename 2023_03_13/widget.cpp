#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText("0");
    ui->pushButton->setText("clear");

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotClearText()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slotSetText()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotClearText(void)
{
    ui->textEdit->clear();
}

void Widget::slotSetText(void)
{
QString myStr;
myStr=ui->lineEdit->text();
//myStr+=". Welcome to QT5 world.\nThis is simple example.\nmakeutil.tistory.com";
ui->textEdit->setText(myStr);
}
