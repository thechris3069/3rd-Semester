#include "robotergui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoboterGUI w;
    w.show();

    return a.exec();
}
