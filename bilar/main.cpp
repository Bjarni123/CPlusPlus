#include <iostream>
#include <string>
#include <iomanip>

#include "bill.h"

using namespace std;

int main() {
    // new -> delete

    /* 
    int *h = new int(99);
    int i = 55;

    cout << &h << ":" << h << ":" << *h << "\n";
    cout << &i << ":" << i << "\n";

    delete h;
    */

    Bill *bilar = new Bill[5];
    bilar[2] = Bill(10, "Toyota", "Rauður");

    // int fjoldi = sizeof(bilar) / sizeof(bilar[0]);

    for (int i = 0; i < 5; i++) {
        if (bilar[i].getID() != -1) {
            bilar[i].prenta();
        }
    }

    Bill *nytt_array = new Bill[10];
    for (int i = 0; i < 5; i++) {
        nytt_array[i] = bilar[i];
    }
    delete [] bilar;
    bilar = nytt_array;

    return 0;
}