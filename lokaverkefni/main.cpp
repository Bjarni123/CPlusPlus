#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // <stdlib.h> fyrir mac
#include <ctime>
#include <sstream>

#include <fstream> // filestream

#include "husgogn.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

int main() {
    Husgogn hg;
    string inntak, skipun, tegund;
    int nrIT, stadsetningIT, verdIT, aukaIT, husIT, nr2IT;

    saveDefaultColor();

    do {
        setColor(BLUE);
        cout << "Sláðu inn skipun: ";
        setColor(WHITE);
        getline(cin, inntak);
        
        stringstream ss;
        ss << inntak;
        ss >> skipun;
        if (skipun == "skra") {
            ss >> tegund >> nrIT >> stadsetningIT >> verdIT >> aukaIT;
            if (tegund == "bord") {
                hg.skraBord(nrIT, stadsetningIT, verdIT, aukaIT);
            } else if (tegund == "stol") {
                hg.skraStol(nrIT, stadsetningIT, verdIT, aukaIT);
            } else if (tegund == "skjavarpa") {
                hg.skraSkjavarpa(nrIT, stadsetningIT, verdIT, aukaIT);
            } else if (tegund == "tolvu") {
                hg.skraTolvu(nrIT, stadsetningIT, verdIT, aukaIT);
            } else if (tegund == "profunargogn") {
                hg.skraBord(501, 21209, 1000, 4);
                hg.skraBord(502, 21209, 2000, 2);
                hg.skraStol(503, 21209, 4000, 0);
                hg.skraStol(504, 21209, 4000, 0);
                hg.skraSkjavarpa(505, 10410, 100000, 4000);
                hg.skraSkjavarpa(506, 21209, 100000, 4000);
                hg.skraTolvu(507, 21209, 50000, 2019);
                hg.skraTolvu(508, 21209, 50000, 2019);
                hg.skraTolvu(509, 21209, 50000, 2019);
                hg.skraTolvu(510, 21209, 50000, 2019);
            } else {
                setColor(RED);
                cout << "Kann ekki að skrá " << tegund << "!!!\n";
            }
        } else if (skipun == "save") {
            cout << "save\n";
        } else if (skipun == "countinue") {
            cout << "countinue\n";
        } else if (skipun == "prenta") {
            cout << "\n";
            ss >> tegund;
            if (tegund == "allt") {
                hg.prentaAllt();
            } else if (tegund == "bord") {
                hg.prentaBord();
            } else if (tegund == "stola") {
                hg.prentaStol();
            } else if (tegund == "skjavarpa") {
                hg.prentaSkjavarpa();
            } else if (tegund == "tolvur") {
                hg.prentaTolvu();
            } else if (tegund == "hus") {
                ss >> husIT;
                hg.prentaBunadIHusi(husIT);
            } else if (tegund == "herbergi") {
                ss >> stadsetningIT;
                hg.prentaBunadIHusiHaedStofu(stadsetningIT);
            } else {
                nrIT = stoi(tegund);
                if (!hg.skodaBunad(nrIT)) {
                    cout << "Fann ekki búnað með númerinu: " << nrIT << "\n";
                }
            }
        } else if (skipun == "eyda") {
            cout << "\n";
            ss >> nrIT;
            if (!hg.eydaBunadi(nrIT)) {
                cout << "Fann ekki búnað með númerinu: " << nrIT << "\n";
            }
        } else if (skipun == "uppfaera") {
            ss >> tegund;
            if (tegund == "stadsetningu") {
                ss >> nrIT >> stadsetningIT;
                hg.uppfaeraStadsetningu(nrIT, stadsetningIT);
            } else if (tegund == "numer") {
                ss >> nrIT >> nr2IT;
                hg.uppfaeraIndex(nrIT, nr2IT);
            } else if (tegund == "verd") {
                ss >> nrIT >> verdIT;
                hg.uppfaeraVerd(nrIT, verdIT);
            } else {
                cout << "Skil ekki skipuninna " << tegund << "!\n";
            }
        } else if (skipun == "haetta") {
            cout << "\nTakk fyrir\n";
        } else {
            cout << "Skil ekki skipuninna " << skipun << "!!!\n";
        }
        
    cout << "\n";
    } while (skipun != "haetta");

    resetColor();
    return 0;
}