#include <iostream>

using namespace std;

void xhange(int &i, int &k)
{
int temp;
temp = k;
k = i;
i = temp;

}

int main()
{
    int zahl1 = 100, zahl2 = 2;
    string name1 = "Hello World";
    xhange(zahl1, zahl2);
    string name;
    string name3 = "suess";
    name1.append( name3);

    cout << name1 << endl;
    return 0;
}
