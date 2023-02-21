#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Lykkjur: while, do-while, for-lykkjur

    float pi = 23.14;
    cout << fixed << setprecision(1) << pi << "\n";

    /*
    int i = 0;
    while (i < 5) {
        cout << ++i << "\n";
    }
    
    cout << "\n";

    int k = 5;
    while (k--) {
        cout << k << "\n";
    }

    cout << "\n";
    

    int q = -1;
    do {
        cout << q << "\n";
        q--;
    } while(q > 0);

    cout << "\n";
    

    int i = 99;

    for (int i = 0; i < 5; i++) {
        cout << i << "\n";
    }
    cout << i << "\n";


    cout << "\n";
    string strengur = "Geir";
    for (char c : strengur) {
        cout << c << "\n";
    }
    
    cout << "\n";

    */

    int j = 11;
    int p = 4;
    if (j > 11 && p == 4) {
        cout << "J er stærra en 11\n";
    }
    else if (j < 11 || p !=4) {
        cout << "j er minna er 11\n";
    } else {
        cout << "j er 11\n";
    }
    return 0;
}