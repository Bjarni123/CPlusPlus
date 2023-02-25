#include <iostream>
#include <string>
#include <iomanip>

#include <fstream> // filestream

using namespace std;

int main() {
    int j = 10, k = 20;
    string texti = "abc";

    ofstream skrifa("skraarvinnsla/gogn.txt", fstream::app);
    if (!skrifa) {
        cout << "gat ekki opnað skrá \n";
    } else {
        skrifa << " " << texti << " " << j << " " << k << endl;
    }
    skrifa.close();

    ifstream lesa("skraarvinnsla/gogn.txt");
    if (!lesa) {
        cout << "gat ekki lesið skrá\n";
    } else {
        while (lesa >> texti >> j >> k) {
            cout << texti << " " << j << " " << k << endl;
        }
    }

    lesa.close();

    return 0;
}