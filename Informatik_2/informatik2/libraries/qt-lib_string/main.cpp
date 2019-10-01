// Beispiel zur Nutzung der Klasse QString aus der Qt-Bibliothek
// Claudia Meitinger
// -> Vorlesung 19.3.2019

#include <QCoreApplication>
#include <QString>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name;

    name = "Claudia";
    cout << name.toStdString() << endl;

    name.append(" Meitinger");
    cout << name.toStdString() << endl;

    cout << "Laenge des Namens: " << name.size() << endl;

    return a.exec();
}

