#include "robotergui.h"
#include "ui_robotergui.h"

#include <iostream>
using namespace std;

RoboterGUI::RoboterGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoboterGUI)
{
    ui->setupUi(this);
    cout << "Konstruktor RoboterGUI (ohne Hardware...)" << endl;
}

RoboterGUI::~RoboterGUI()
{
    delete ui;
    cout << "Destruktor RoboterGUI (ohne Hardware...)" << endl;
}

void RoboterGUI::on_sendButton_clicked()
{
    cout << "Send Button clicked!" << endl;

    QString kommando;
    kommando = "0;";
    kommando += QString::number(ui->wert0->value());

    std::cout << "Kommando: " << kommando.toStdString() << std::endl;
}
