#ifndef CAVE_H
#define CAVE_H

#include <QWidget>

namespace Ui {
class Cave;
}

class Cave : public QWidget
{
    Q_OBJECT

public:
    explicit Cave(QWidget *parent = 0);
    ~Cave();

private slots:
    void on_user_input_textChanged(const QString &arg1);

private:
    Ui::Cave *ui;
};

#endif // CAVE_H
