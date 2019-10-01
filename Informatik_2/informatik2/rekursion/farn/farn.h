#ifndef FARN_H
#define FARN_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Farn;
}

class Farn : public QWidget
{
    Q_OBJECT

public:
    explicit Farn(QWidget *parent = 0);
    ~Farn();

private slots:
    void on_drawButton_clicked();

    void on_angleSlider_valueChanged(int value);

    void on_lengthSlider_valueChanged(int value);

private:
    Ui::Farn *ui;
    QGraphicsScene *scene;

    void drawFarn(int x, int y, double angle_deg, int length);
};

#endif // FARN_H
