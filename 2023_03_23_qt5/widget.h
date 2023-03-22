#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <qserialportinfo.h>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void slotSetText_1(void);
    void slotClearText_1(void);
    void slotToggleText_1(void);
    void slotSetText_2(void);
    void slotClearText_2(void);
    void slotToggleText_2(void);
    void slotSetText_3(void);
    void slotClearText_3(void);
    void slotToggleText_3(void);
    void slotSetText_4(void);
    void slotClearText_4(void);
    void slotToggleText_4(void);
    void slotSetText_5(void);
    void slotClearText_5(void);
    void slotToggleText_5(void);
    void slotSetText_6(void);
    void slotClearText_6(void);
    void slotToggleText_6(void);
    void slotSetText_7(void);
    void slotClearText_7(void);
    void slotToggleText_7(void);
    void slotSetText_8(void);
    void slotClearText_8(void);
    void slotToggleText_8(void);
    void slotSetText_HEX(void);
    void slotClearText_HEX(void);
    void slotClearText_HEX_TEXT(void);
    void updateFrames(void);
    void setTextDecimal(void);
    void on_pushButton_2_clicked(void);
    void on_pushButton_3_clicked(void);
    void Send_Button(void);
    void readData(void);



private:
    Ui::Widget *ui;
    QSerialPort *pPort;
    QString portname;
    struct DATA{
        unsigned char data_array1 = 0;
    };

};

#endif // WIDGET_H


