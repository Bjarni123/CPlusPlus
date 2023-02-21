#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int main() {
    int val;

    /* char stafur = 'A' + random_tala_fra_0_til_og_með_25;
    stafur++
    cout << stafur << "\n"; */

    return 0;

    do {
        cout << "Sláðu inn heiltölu (99 til að hætta): ";
        cin >> val;

        switch (val) {
            case 1:
                cout << "Þú valdir 1\n";
                break;
            
            case 2:
                cout << "Þú valdir 2\n";
                break;
            
            case 5:
            case 6:
                cout << "Þú valdir 5 eða 6\n";
                break;

            case 99:
                cout << "Takk fyrir í dag\n";
                break;

            default:
                cout << "Þú valdir eitthvað annað!\n";
                break;
        }
        cin.clear();
        cin.ignore();
    } while (val != 99);

    return 0;
}