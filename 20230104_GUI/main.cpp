#include "GUITEST3.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUITEST3 w;

    w.setWindowTitle("My First Qt Program");
    w.resize(600, 400);
    w.show();
    return a.exec();
}
