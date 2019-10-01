#ifndef ROBOTERGUI_H
#define ROBOTERGUI_H

#include <QWidget>

namespace Ui {
class RoboterGUI;
}

class RoboterGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RoboterGUI(QWidget *parent = 0);
    ~RoboterGUI();

private slots:
    void on_sendButton_clicked();

private:
    Ui::RoboterGUI *ui;
};

#endif // ROBOTERGUI_H
