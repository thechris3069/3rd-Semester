#include "cave.h"
#include "ui_cave.h"

#include <QLabel>

Cave::Cave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cave)
{
    ui->setupUi(this);

    for (unsigned int row = 0; row < 8; row++) {
        for (unsigned int col = 0; col < 10; col++) {
            ui->cave_layout->addWidget(new QLabel("x"), row, col);
        }
    }

    ui->user_input->setFocus();
}

Cave::~Cave()
{
    delete ui;
}

void Cave::on_user_input_textChanged(const QString &arg1)
{
    ui->text_output->append(arg1);

    QLabel *p1 = reinterpret_cast<QLabel*>(ui->cave_layout->itemAtPosition(3, 3)->widget());
    p1->setText("hallo");
    QLabel *p2 = reinterpret_cast<QLabel*>(ui->cave_layout->itemAtPosition(4, 4)->widget());
    p2->setPixmap(QPixmap("../smiley.png").scaled(100, 100));

    ui->user_input->clear();
}
