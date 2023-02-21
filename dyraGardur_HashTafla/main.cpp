#include <iostream>
#include <string>
#include <cstdlib> // <stdlib.h> fyrir mac
#include <ctime>
#include <sstream>

#include "rlutil.h"
#include "Dyragardur.h"

using namespace std;
using namespace rlutil;

// skrá hund Snati 7 8
// skrá kött Fluffy 9 Konni
// prenta allt
// prenta hunda
// prenta ketti
// skoða Snati
// eyða Snat
// hætta

int main() {
    Dyragardur dg;
    string inntak, skipun, tegund, nafn, eigandi;
    int aldur, einkunn;

    saveDefaultColor();

    do {
        setColor(BLUE);
        cout << "Sláðu inn skipun: ";
        setColor(WHITE);
        getline(cin, inntak);

        stringstream ss;
        ss << inntak;
        ss >> skipun;
        if (skipun == "skrá") {
            ss >> tegund;
            if (tegund == "hund") {
                // skrá hund Snatti 7 8
                ss >> nafn >> aldur >> einkunn;
                dg.skraHund(aldur, nafn, einkunn);
            } else if (tegund == "kött") {
                // skrá kött Fluffy 9 Konni
                ss >> nafn >> aldur >> eigandi;
                dg.skraKott(aldur, nafn, eigandi);
            } else {
                setColor(RED);
                cout << "Kann ekki að skrá " << tegund << "!!!\n";
            }
        } else if (skipun == "prenta") {
            ss >> tegund;
            if (tegund == "allt") {
                dg.prentaAllt();
            } else if (tegund == "hunda") {
                dg.prentaHunda();
            } else if (tegund == "ketti") {
                dg.prentaKetti();
            } else {
                setColor(RED);
                cout << "Veit ekki hvað " << tegund << "er!!!\n";
            }
        } else if (skipun == "skoða") {
            ss >> nafn;
            if (!dg.skodaDyr(nafn)) {
                setColor(RED);
                cout << "Fann ekki dýr með nafninu " << nafn << "!!!\n";
            }
        } else if (skipun == "eyða") {
            ss >> nafn;
            if (dg.eydaDyri(nafn)) {
                cout << "Eyddi " << nafn << " út listanum.\n";
            } else {
                setColor(RED);
                cout << "Fann ekki dýr með nafninu " << nafn << "!!!\n";
            }
        } else if (skipun != "hætta") {
            setColor(RED);
            cout << "Skil ekki orðið " << skipun << "!!!\n";
        }

    } while (skipun != "hætta");


    resetColor();
    return 0;
}