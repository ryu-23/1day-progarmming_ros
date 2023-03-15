#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->IN_1->setText("IN_1");
    ui->IN_2->setText("IN_2");

    QObject::connect(ui->IN_1, &QAbstractButton::clicked, this, &Widget::slotToggleText_1);
    QObject::connect(ui->IN_2, &QAbstractButton::clicked, this, &Widget::slotToggleText_2);

    QObject::connect(ui->INPUT_SEND_BUTTEN, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in1Value + ", " + in2Value); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotSetText_1()
{
    ui->lineEdit->setText("1");
}

void Widget::slotClearText_1()
{
    ui->lineEdit->setText("0");
}

void Widget::slotToggleText_1()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_1()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_1(); // 이전에 호출된 슬롯이 slotSetText_1()인 경우, slotClearText_1()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_1(); // 이전에 호출된 슬롯이 slotClearText_1()인 경우, slotSetText_1()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}

void Widget::slotSetText_2()
{
    ui->lineEdit_2->setText("1");
}

void Widget::slotClearText_2()
{
    ui->lineEdit_2->setText("0");
}

void Widget::slotToggleText_2()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_2(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_2(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}

