#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUITEST3.h"

class GUITEST3 : public QMainWindow
{
    Q_OBJECT

public:
    GUITEST3(QWidget *parent = nullptr);
    ~GUITEST3();

private:
    Ui::GUITEST3Class ui;
};
