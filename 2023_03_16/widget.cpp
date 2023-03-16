#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->HEX_INPUT->setText("0");
    ui->HEX_INPUT_CLEAR->setText("clear");

    QObject::connect(ui->HEX_INPUT_CLEAR,SIGNAL(clicked()),this,SLOT(slotClearText_HEX()));
    connect(ui->HEX_INPUT_SEND,SIGNAL(clicked()),this,SLOT(slotSetText_HEX()));
    connect(ui->HEX_TEXT_CLEAR,SIGNAL(clicked()),this,SLOT(slotClearText_HEX_TEXT()));
    connect(ui->LED_SET, &QPushButton::clicked, this, &Widget::updateFrames);

    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->IN_1->setText("IN_1");
    ui->IN_2->setText("IN_2");

    QObject::connect(ui->IN_1, &QAbstractButton::clicked, this, &Widget::slotToggleText_1);
    QObject::connect(ui->IN_2, &QAbstractButton::clicked, this, &Widget::slotToggleText_2);

    QObject::connect(ui->INPUT_SEND_BUTTEN, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in1Value + " " + in2Value); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.

    ///////
    // 버튼을 누를 때마다 updateFrames() 함수 호


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
//////////////////////////////////////

void Widget::slotClearText_HEX(void)
{
    ui->HEX_INPUT->clear();
}

void Widget::slotClearText_HEX_TEXT(void)
{
    ui->HEX_TEXT->clear();
}

void Widget::slotSetText_HEX(void)
{
QString myStr;
myStr=ui->HEX_INPUT->text();
//myStr+=". Welcome to QT5 world.\nThis is simple example.\nmakeutil.tistory.com";
ui->HEX_TEXT->setText(myStr);
}

void Widget::updateFrames(void) {


    // HEX_INPUT의 입력값을 가져옴
    QString hexValue = ui->HEX_INPUT->text();

    // 입력값을 10자리의 2진수 문자열로 변환
    QString binaryValue = QString("%1").arg(hexValue.toUInt(nullptr, 10), 8, 2, QLatin1Char('0'));

    // 변환된 2진수 문자열에서 각 자리의 값을 배열에 저장
    int values[8];
    for (int i = 0; i < 8; i++) {
    values[i] = binaryValue.mid(i, 1).toInt();
    }


// frame 포인터 배열
QFrame* frames[8] = {ui->frame_1, ui->frame_2, ui->frame_3, ui->frame_4,
ui->frame_5, ui->frame_6, ui->frame_7, ui->frame_8};

// 배열의 값을 기반으로 frame 색상 설정
for (int i = 0; i < 8; i++) {
if (values[i] == 0) {
frames[i]->setStyleSheet("background-color: red;");
} else {
frames[i]->setStyleSheet("background-color: blue;");
}
}
}

