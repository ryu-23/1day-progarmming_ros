#include "widget.h"
#include "ui_widget.h"
#include <QtCore/QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 버튼에 대한 조건문을 추가하여 로직을 구현합니다.

    if (ui->pushButton_2->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 2 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 2 is not checked!";
    }

    if (ui->pushButton_3->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 3 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 3 is not checked!";
    }

    if (ui->pushButton_4->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 4 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 4 is not checked!";
    }

    if (ui->pushButton_5->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 5 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 5 is not checked!";
    }

    if (ui->pushButton_6->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 6 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 6 is not checked!";
    }
    if (ui->pushButton_7->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 7 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 7 is not checked!";
    }
    if (ui->pushButton_8->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 8 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 8 is not checked!";
    }

    // 버튼에 대한 조건문을 추가하여 로직을 구현합니다.
    if (ui->pushButton_9->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 9 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 9 is not checked!";
    }

    if (ui->pushButton_10->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 10 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 10 is not checked!";
    }

    if (ui->pushButton_11->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 11 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 11 is not checked!";
    }

    if (ui->pushButton_12->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 12 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 12 is not checked!";
    }

    if (ui->pushButton_13->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 13 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 13 is not checked!";
    }

    if (ui->pushButton_14->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 14 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 14 is not checked!";
    }
    if (ui->pushButton_15->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 15 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 15 is not checked!";
    }
    if (ui->pushButton_16->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "Button 16 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "Button 16 is not checked!";
    }
}

void Widget::on_checkBox_pressed()
{
    // 버튼에 대한 조건문을 추가하여 로직을 구현합니다.
    if (!ui->checkBox->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "checkBox is checked!";

        if (ui->pushButton->isChecked()) {
            // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
            qDebug() << "Button 1 is checked!";
        } else {
            // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
            qDebug() << "Button 1 is not checked!";
        }
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "checkBox is not checked!";
    }

    if (!ui->checkBox_2->isChecked()) {
        // 버튼이 체크되어 있으면 "Button is checked!" 메시지를 출력합니다.
        qDebug() << "checkBox_2 is checked!";
    } else {
        // 버튼이 체크되어 있지 않으면 "Button is not checked!" 메시지를 출력합니다.
        qDebug() << "checkBox_2 is not checked!";
    }


}
