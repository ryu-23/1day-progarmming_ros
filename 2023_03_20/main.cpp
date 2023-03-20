#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    // 시리얼 포트 정보 가져오기
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    QSerialPort serial;

    // 포트 정보 확인
    qDebug() << "Available ports:";
    for (const QSerialPortInfo &port : portList) {
        qDebug() << port.portName() << port.description();
    }

    // 시리얼 포트 설정
    serial.setPortName("/dev/ttyUSB12"); // 시리얼 포트 경로 설정
    serial.setBaudRate(QSerialPort::Baud115200); // 통신 속도 설정
    serial.setDataBits(QSerialPort::Data8); // 데이터 비트 설정
    serial.setParity(QSerialPort::NoParity); // 패리티 비트 설정
    serial.setStopBits(QSerialPort::OneStop); // 정지 비트 설정
    serial.setFlowControl(QSerialPort::NoFlowControl); // 흐름 제어 설정

    // 시리얼 포트 열기
    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open serial port!";
        return 1;
    }

    qDebug() << "Serial port is opened:" << serial.portName();

    // 다른 PC로부터 데이터 수신 대기
    QObject::connect(&serial, &QSerialPort::readyRead, [&]() {
        QByteArray data = serial.readAll();
        qDebug() << "Received data:" << data;
    });

    // 다른 PC로 데이터 전송
    QByteArray sendData("11110000");
    int bytesWritten = static_cast<int>(serial.write(sendData));
    if (bytesWritten == -1) {
        qDebug() << "Failed to write data to serial port!";
    } else {
        qDebug() << "Sent data:" << sendData;
    }

    // 애플리케이션 실행
    return a.exec();
}
