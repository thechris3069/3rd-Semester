/*
 * Vorlesungsbeispiel Informatik 2
 * Rekursives Zeichnen eines Farns
 * Claudia Meitinger
 */

#include "farn.h"
#include "ui_farn.h"
#include <cmath>

Farn::Farn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Farn)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->angleLabel->setText("Winkel: " + QString::number(ui->angleSlider->value()));
    ui->lengthLabel->setText("Laenge: " + QString::number(ui->lengthSlider->value()));
}

Farn::~Farn()
{
    delete scene;
    delete ui;
}

void Farn::drawFarn(int x, int y, double angle_deg, int length)
{
    int xEnde = x + cos(angle_deg/180.0*M_PI) * length;
    int yEnde = y + sin(angle_deg/180.0*M_PI) * length;

    // Trivialer Fall
    if (length < 5)
        return;

    // Rekursiver Fall
    scene->addLine(x, y, xEnde, yEnde);
    drawFarn(xEnde, yEnde, angle_deg + 45, length * 0.5);
    drawFarn(xEnde, yEnde, angle_deg -  5, length * 0.7);
    drawFarn(xEnde, yEnde, angle_deg - 30, length * 0.4);
}

void Farn::on_drawButton_clicked()
{
    scene->clear();
    drawFarn(0, 0, ui->angleSlider->value(), ui->lengthSlider->value());
    ui->treeView->setScene(scene);
    ui->treeView->show();
}

void Farn::on_angleSlider_valueChanged(int value)
{
    ui->angleLabel->setText("Winkel: " + QString::number(value));
}

void Farn::on_lengthSlider_valueChanged(int value)
{
    ui->lengthLabel->setText("Laenge: " + QString::number(value));
}
