#include "widget.h"
#include "ui_widget.h"
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pPort=new QSerialPort(this);

    ui->HEX_INPUT->setText("0");
    ui->HEX_INPUT_CLEAR->setText("clear");
    ui->HEX_INPUT_CLEAR->setText("clear");

    QObject::connect(ui->HEX_INPUT_CLEAR,SIGNAL(clicked()),this,SLOT(slotClearText_HEX()));
    connect(ui->HEX_INPUT_SEND,SIGNAL(clicked()),this,SLOT(slotSetText_HEX()));
    connect(ui->HEX_TEXT_CLEAR,SIGNAL(clicked()),this,SLOT(slotClearText_HEX_TEXT()));
    connect(ui->INPUT_SEND_BUTTEN,SIGNAL(clicked()),this,SLOT(setTextDecimal()));
    connect(ui->LED_SET, &QPushButton::clicked, this, &Widget::updateFrames);
    connect(ui->INPUT_SEND_BUTTEN,SIGNAL(clicked()),this,SLOT(Send_Button()));

    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");
    ui->lineEdit_4->setText("0");
    ui->lineEdit_5->setText("0");
    ui->lineEdit_6->setText("0");
    ui->lineEdit_7->setText("0");
    ui->lineEdit_8->setText("0");
    ui->IN_1->setText("IN_1");
    ui->IN_2->setText("IN_2");

    QObject::connect(ui->IN_1, &QAbstractButton::clicked, this, &Widget::slotToggleText_1);
    connect(ui->IN_2, &QAbstractButton::clicked, this, &Widget::slotToggleText_2);
    connect(ui->IN_3, &QAbstractButton::clicked, this, &Widget::slotToggleText_3);
    connect(ui->IN_4, &QAbstractButton::clicked, this, &Widget::slotToggleText_4);
    connect(ui->IN_5, &QAbstractButton::clicked, this, &Widget::slotToggleText_5);
    connect(ui->IN_6, &QAbstractButton::clicked, this, &Widget::slotToggleText_6);
    connect(ui->IN_7, &QAbstractButton::clicked, this, &Widget::slotToggleText_7);
    connect(ui->IN_8, &QAbstractButton::clicked, this, &Widget::slotToggleText_8);

    QObject::connect(ui->INPUT_SEND_BUTTEN, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in1Value + " " + in2Value + " " + in3Value + " " + in4Value + " " + in5Value + " " + in6Value  + " " + in7Value  + " " + in8Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.

    connect(pPort, &QSerialPort::readyRead, this, &Widget::readData);

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

void Widget::slotSetText_3()
{
    ui->lineEdit_3->setText("1");
}

void Widget::slotClearText_3()
{
    ui->lineEdit_3->setText("0");
}

void Widget::slotToggleText_3()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_3(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_3(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}


void Widget::slotSetText_4()
{
    ui->lineEdit_4->setText("1");
}

void Widget::slotClearText_4()
{
    ui->lineEdit_4->setText("0");
}


void Widget::slotToggleText_4()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_4(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_4(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}
void Widget::slotSetText_5()
{
    ui->lineEdit_5->setText("1");
}

void Widget::slotClearText_5()
{
    ui->lineEdit_5->setText("0");
}


void Widget::slotToggleText_5()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_5(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_5(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}

void Widget::slotSetText_6()
{
    ui->lineEdit_6->setText("1");
}

void Widget::slotClearText_6()
{
    ui->lineEdit_6->setText("0");
}


void Widget::slotToggleText_6()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_6(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_6(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}

void Widget::slotSetText_7()
{
    ui->lineEdit_7->setText("1");
}

void Widget::slotClearText_7()
{
    ui->lineEdit_7->setText("0");
}


void Widget::slotToggleText_7()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_7(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_7(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}

void Widget::slotSetText_8()
{
    ui->lineEdit_8->setText("1");
}

void Widget::slotClearText_8()
{
    ui->lineEdit_8->setText("0");
}


void Widget::slotToggleText_8()
{
    static bool isSetText = false; // 이전에 호출된 슬롯이 slotSetText_2()인지 여부를 저장하는 변수
    if (isSetText) {
        slotClearText_8(); // 이전에 호출된 슬롯이 slotSetText_2()인 경우, slotClearText_2()를 호출하여 "0"으로 설정합니다.
    } else {
        slotSetText_8(); // 이전에 호출된 슬롯이 slotClearText_2()인 경우, slotSetText_2()를 호출하여 "1"으로 설정합니다.
    }
    isSetText = !isSetText; // 이전에 호출된 슬롯을 변경합니다.
}
//////////////////////////////////////


void Widget::on_pushButton_2_clicked()
{
    pPort->setPortName("ttyUSB0");//or ttyACM1, check qDebug Message.
    pPort->setBaudRate(QSerialPort::Baud115200);
    pPort->setDataBits(QSerialPort::Data8);
    pPort->setParity(QSerialPort::NoParity);
    if(!(pPort->open(QIODevice::ReadWrite)))
    qDebug()<<"\n Serial Port Open Error";
    else
    qDebug()<<"\n Serial Port Open Success";

}


void Widget::on_pushButton_3_clicked()
{
    pPort->close();
    qDebug()<<"\n Serial Port close close";
}

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
    QString input = ui->HEX_INPUT->text(); // 입력된 16진수 값을 가져옵니다.
    bool ok;
    quint64 value = input.toULongLong(&ok, 16); // 16진수 값을 unsigned long long 형태로 변환합니다.
    if (!ok) {
    return;
    }
    QString binaryString = QString("%1").arg(value, 8, 2, QChar('0')); // 변환된 값을 8자리의 2진수 문자열로 변환합니다.
    ui->HEX_TEXT->setText(binaryString); // 변환된 값을 출력합니다.
}


void Widget::readData()
{
    //bool _ok;
    //This code is to read all data on serial port
    QByteArray data = pPort->readAll();
    qDebug() << data.toHex();  //Here is the read data as Hex values

}

void Widget::updateFrames(void) {


    // HEX_INPUT의 입력값을 가져옴
    QString hexValue = ui->HEX_INPUT->text();

    // 입력값을 10자리의 2진수 문자열로 변환
    QString binaryValue = QString("%1").arg(hexValue.toUInt(nullptr, 16), 8, 2, QLatin1Char('0'));

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

void Widget::setTextDecimal(void) {



}

void Widget::Send_Button(void)
{
     QString myStr_2, myStr2_2;

       myStr_2+=ui->lineEdit_8->text();
       myStr_2+=ui->lineEdit_7->text();
       myStr_2+=ui->lineEdit_6->text();
       myStr_2+=ui->lineEdit_5->text();
       myStr_2+=ui->lineEdit_4->text();
       myStr_2+=ui->lineEdit_3->text();
       myStr_2+=ui->lineEdit_2->text();
       myStr_2+=ui->lineEdit->text();

       int oac = 0, i = 0, n, strTonum ;
       strTonum = myStr_2.toInt();

           while (strTonum != 0) {
               n = strTonum % 10;
               strTonum /= 10;
               oac += n * pow(2, i);
               ++i;
           }
       myStr2_2 = myStr2_2.setNum(oac);

       ui->INPUT_SEND_CHECK->setText(myStr2_2);

    DATA *send = new DATA;

    send->data_array1 = (unsigned char)myStr2_2.toDouble();

    auto packet = reinterpret_cast<char*>(send);
    pPort->write(packet,sizeof (DATA));
    qDebug()<<"\n HIHI";

    delete send;

}


