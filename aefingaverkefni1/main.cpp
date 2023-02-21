#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int main() {
    // A liður
    /*
    float summa = 0;
    int tala;
    for (int i = 0; i < 5; i++) {
        cout << "Sláðu inn tölu: ";
        cin >> tala;
        summa += tala;
    }
    cout << "Summa talnanna er: " << fixed << setprecision(1) << summa << 
    "\nMeðaltal talnanna er: " << fixed << setprecision(1) << summa / 5. << "\n";
    */

    float summa = 0, count = 0;
    int tala = 0;
    for (;;) {
        cout << "Sláðu inn -1 til þess að hætta eða sláðu inn tölu: ";
        cin >> tala;
        if (tala == -1) break;
        summa += tala;
        count++;
    }

    cout << "Summa talnanna er: " << fixed << setprecision(1) << summa << 
    "\nMeðaltal talnanna er: " << fixed << setprecision(1) << summa / count << "\n";

}