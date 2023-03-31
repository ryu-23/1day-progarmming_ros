#include "widget.h"
#include "ui_widget.h"
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pPort=new QSerialPort(this);

    connect(pPort, &QSerialPort::readyRead, this, &Widget::readData);


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

    QObject::connect(ui->IN_1, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_2, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_3, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_4, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_5, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_6, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_7, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_8, &QPushButton::clicked, this, [this](){
    QString in1Value = ui->lineEdit->text(); // IN_1의 값을 가져옵니다.
    QString in2Value = ui->lineEdit_2->text(); // IN_2의 값을 가져옵니다.
    QString in3Value = ui->lineEdit_3->text(); // IN_3의 값을 가져옵니다.
    QString in4Value = ui->lineEdit_4->text(); // IN_4의 값을 가져옵니다.
    QString in5Value = ui->lineEdit_5->text(); // IN_5의 값을 가져옵니다.
    QString in6Value = ui->lineEdit_6->text(); // IN_6의 값을 가져옵니다.
    QString in7Value = ui->lineEdit_7->text(); // IN_7의 값을 가져옵니다.
    QString in8Value = ui->lineEdit_8->text(); // IN_8의 값을 가져옵니다.
    ui->INPUT_SEND->setText(in8Value + " " + in7Value + " " + in6Value + " " + in5Value + " " + in4Value + " " + in3Value  + " " + in2Value  + " " + in1Value  ); // IN_1과 IN_2의 값을 합쳐서 INPUT_SEND에 출력합니다.
    });

    QObject::connect(ui->IN_1,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_1,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_2,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_2,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_3,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_3,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_4,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_4,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_5,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_5,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_6,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_6,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_7,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_7,SIGNAL(clicked()),this,SLOT(initarray()));
    connect(ui->IN_8,SIGNAL(clicked()),this,SLOT(Send_Button()));
    connect(ui->IN_8,SIGNAL(clicked()),this,SLOT(initarray()));
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
void Widget::on_pushButton_5_clicked(void)
{

    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");
    ui->lineEdit_4->setText("0");
    ui->lineEdit_5->setText("0");
    ui->lineEdit_6->setText("0");
    ui->lineEdit_7->setText("0");
    ui->lineEdit_8->setText("0");
    ui->INPUT_SEND->setText("0");
    ui->INPUT_SEND_CHECK->setText("00000000");

    QFrame* frames[8] = {ui->LED_1,ui->LED_2,ui->LED_3,ui->LED_4,ui->LED_5,ui->LED_6,ui->LED_7,ui->LED_8};
    for(int i = 0; i < 8 ; i++)
    {
        frames[i]->setStyleSheet("background-color: red;");
    }
}

void Widget::calculate(int data, int count)
{
    for(int i = 0 ; i < count ; i++)
    {
        Binary[i] = data % 2;
        data /= 2;
    }
}

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



void Widget::initarray(void)
{
    for(int i = 0; i < 8;i++)
    {
        Binary[i] = 0;
    }
}



void Widget::readData()
{
    int DEC_data = 0, ADC_data;
    QString strValue;
    QByteArray data = pPort->readAll();
    qDebug() <<"\n"<<data.size()<<"////"<<data.toHex();  //Here is the read data as Hex values
    ucharArray = reinterpret_cast<const unsigned char*>(data.constData());
    unsigned char hexArray[9];

    for(int i = 0; i < 9 ; ++i)
    {
        hexArray[i] = ucharArray[i];
    }

    qDebug() << ucharArray <<"////"<< hexArray;

    if((hexArray[0] == 174) && (hexArray[1] == 184))
    {
        if(hexArray[2] == 105)
        {
            DEC_data = hexArray[4];
            ADC_val.a[0] = hexArray[5];
            ADC_val.a[1] = hexArray[6];
            ADC_data = ADC_val.data;
            //ADC_data = (ADC_data >= 4096 || ADC_data <= 0) ? ADC_data_old : ADC_data;
            qDebug() << DEC_data << ADC_data;
            //if(ADC_data <= 4096 || ADC_data>=0) ADC_data_old = ADC_data;
        }
        else DEC_data = 0;
    }
    else DEC_data = 0;

    for(int i = 7 ; i >= 0 ; --i)
    {
        Binary[i] = (DEC_data>>i)&1;
    }

    QFrame* frames[8] = {ui->LED_1,ui->LED_2,ui->LED_3,ui->LED_4,ui->LED_5,ui->LED_6,ui->LED_7,ui->LED_8};

    for(int i= 0; i < 8 ; ++i)
    {
        if(Binary[i]==0)    frames[i]->setStyleSheet("background-color: red;");
        else                frames[i]->setStyleSheet("background-color: blue;");
    }

    strValue = QString::number(ADC_data);
    qDebug() << strValue;

    ui->ADC->setText(strValue);


}

int Widget::map(int data, int in_min,int in_max,int out_min,int out_max )
{
    return (data - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Widget::updateFrames(void) {


    // HEX_INPUT의 입력값을 가져옴

    // 입력값을 10자리의 2진수 문자열로 변환

    // 변환된 2진수 문자열에서 각 자리의 값을 배열에 저장
    int values[8];
    for (int i = 0; i < 8; i++) {
    }


// frame 포인터 배열

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

    delete send;

}


