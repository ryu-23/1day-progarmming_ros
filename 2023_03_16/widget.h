#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void slotSetText_HEX(void);
    void slotClearText_HEX(void);
    void slotClearText_HEX_TEXT(void);
    void updateFrames(void);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H


