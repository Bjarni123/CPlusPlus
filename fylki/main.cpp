#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

void prentaFylki(int fylkid[], int staerd) {
    // int staerd = sizeof(annadFylki) / sizeof(annadFylki[0]);
    cout << "Stærð í falli: " << sizeof(fylkid) << "\n";
    for (int i = 0; i < staerd; i++) {
        cout << fylkid[i] << "\n";
    }
}

int main() {
    int fylki[] = {1, 2, 3, 4, 5};
    int annadFylki[5] = {0};

    prentaFylki(fylki, 5);

    cout << "Fylkið: " << fylki << "\n";
    cout << "1. Stakið: " << &fylki[0] << "\n";
    int staerd = sizeof(annadFylki) / sizeof(annadFylki[0]);
    cout << "fjöldi: " << staerd << "\n";

    for (int i = 0; i < staerd; i++) {
        cout << fylki[i] << ":" << &fylki[i] << "\n";
    }

    return 0;
}