/*
 * Einfache Implementierung eines Quicksort
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>::size_type teile(vector<int> &feld, vector<int>::size_type links, vector<int>::size_type rechts)
{
    vector<int>::size_type p = (rechts + links)/2;
    int temp = feld[rechts];
    feld[rechts] = feld[p];
    feld[p] = temp;

    vector<int>::size_type store = links;
    for (vector<int>::size_type i = links; i < rechts; i++) {
        if (feld[i] <= feld[rechts]) {
            temp = feld[i];
            feld[i] = feld[store];
            feld[store] = temp;
            store++;
        }
    }
    temp = feld[rechts];
    feld[rechts] = feld[store];
    feld[store] = temp;

    return store;
}

void quickSort (vector<int> &feld, vector<int>::size_type links, vector<int>::size_type rechts)
{
    if (links < rechts) {
        vector<int>::size_type pi = teile(feld, links, rechts);
        if (pi > 0)
            quickSort(feld, links, pi-1);
        quickSort(feld, pi+1, rechts);
    }
}

int main(void)
{
    // Eigene sort-Implementierung
    vector<int> feld1 {'F', 'B', 'P', 'M', 'D', 'A', 'G', 'H', 'I', 'J', 'L', 'E', 'K', 'V', 'Z', 'C'};

    for (auto f: feld1) {
        cout << static_cast<char>(f) << " ";
    }
    cout << endl;

    quickSort(feld1, 0, feld1.size()-1);

    for (auto f: feld1) {
        cout << static_cast<char>(f) << " ";
    }
    cout << endl;

    // sort-Implementierung der C++ Standardbibliothek
    vector<int> feld2 {'F', 'B', 'P', 'M', 'D', 'A', 'G', 'H', 'I', 'J', 'L', 'E', 'K', 'V', 'Z', 'C'};

    for (auto f: feld2) {
        cout << f << " ";
    }
    cout << endl;

    sort(feld2.begin(), feld2.end());

    for (auto f: feld2) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
