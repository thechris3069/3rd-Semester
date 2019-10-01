// Beispiel zu Standardwerten von Funktionsparametern aus Skript Informatik 2
// Claudia Meitinger
// -> Vorlesung 19.3.2019

#include <iostream>
using namespace std;

double rechne(double op1, int op2 = 1, char op = '*');

int main ()
{
    rechne(7.2, 1, '-');   // ok: op1 7.2, op2 1, op '-'
    rechne(7.2);           // ok: op1 7.2, op2 1, op '*'
    rechne(4.2, 4, '+');   // ok: op1 4.2, op2 4, op '+'
    rechne(4.2, 3);        // ok: op1 4.2, op2 3, op '*'
    rechne(1.2, '/');      // problematisch: op1 1.2, op2 47, op '*'
                           // Parameter koennen nur von hinten weg-
                           // gelassen werden!
//    rechne();              // fehlerhaft: op1 muss angegeben werden
    return 0;
}

double rechne(double op1, int op2, char op)
{
    cout << "Rechne " << op1 << op << op2 << "..." << endl;
    switch(op)
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    default: cout << "Unbekannter Operator '" << op << "'!" << endl;
    }
    return 0.0;
}
