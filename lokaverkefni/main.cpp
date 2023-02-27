#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // <stdlib.h> fyrir mac
#include <ctime>
#include <sstream>
#include <filesystem>

// https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
#include <fstream> // filestream

#include "husgogn.h"
#include "rlutil.h"

// https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
namespace fs = std::filesystem;

using namespace std;
using namespace rlutil;

void errorMsg(string message) {
    setColor(RED);
    cout << message << "\n";
    setColor(WHITE);
}

int main() {
    Husgogn hg;
    string inntak, skipun, tegund, path;
    int nrIT, stadsetningIT, verdIT, aukaIT, husIT, nr2IT;

    setColor(MAGENTA);

    // https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
    // Hér checkea ég hvaða skjöl eru í saves folderinu til þess að prenta þau út.
    string pathToSaves = "lokaverkefni/saves/";
    for (const auto & entry : fs::directory_iterator(pathToSaves)) {
        string daPath = entry.path();
        cout << daPath.substr(19) << endl;
    }
    cout << "Einnig er hægt að búa til þitt eigið skjal með því að einfaldlega skrifa nýja nafnið á skránni\n";

    bool geraLoopu = true;

    do {
        setColor(BLUE);
        cout << "\nSláðu inn hvaða skja þú vilt vinna við: ";
        setColor(WHITE);
        cin >> path;

        ifstream lesa("lokaverkefni/saves/" + path);
        if (!lesa) {
            errorMsg("gat ekki lesið skrá");
        } else {
            while (lesa >> tegund >> nrIT >> stadsetningIT >> verdIT >> aukaIT) {
                if (tegund == "Bord") {
                    hg.skraBord(nrIT, stadsetningIT, verdIT, aukaIT);
                } else if (tegund == "Stoll") {
                    hg.skraStol(nrIT, stadsetningIT, verdIT, aukaIT);
                } else if (tegund == "Skjavarpi") {
                    hg.skraSkjavarpa(nrIT, stadsetningIT, verdIT, aukaIT);
                } else if (tegund == "Tolva") {
                    hg.skraTolvu(nrIT, stadsetningIT, verdIT, aukaIT);
                }
            }
            geraLoopu = false;
        }
        lesa.close();
    } while (geraLoopu);

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
                ifstream lesa("lokaverkefni/saves/profunargogn");
                if (!lesa) {
                    errorMsg("gat ekki lesið skrá");
                } else {
                    while (lesa >> tegund >> nrIT >> stadsetningIT >> verdIT >> aukaIT) {
                        if (tegund == "Bord") {
                            hg.skraBord(nrIT, stadsetningIT, verdIT, aukaIT);
                        } else if (tegund == "Stoll") {
                            hg.skraStol(nrIT, stadsetningIT, verdIT, aukaIT);
                        } else if (tegund == "Skjavarpi") {
                            hg.skraSkjavarpa(nrIT, stadsetningIT, verdIT, aukaIT);
                        } else if (tegund == "Tolva") {
                            hg.skraTolvu(nrIT, stadsetningIT, verdIT, aukaIT);
                        }
                    }
                }
            } else {
                errorMsg("Kann ekki að skrá " + tegund);
            }
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
                    errorMsg("Fann ekki búnað með númerinu: " + nrIT);
                }
            }
        } else if (skipun == "eyda") {
            cout << "\n";
            ss >> nrIT;
            if (!hg.eydaBunadi(nrIT)) {
                errorMsg("Fann ekki búnað með númerinu: " + nrIT);
            }
        } else if (skipun == "uppfaera") {
            ss >> tegund;
            if (tegund == "stadsetningu") {
                ss >> nrIT >> stadsetningIT;
                if (!hg.uppfaeraStadsetningu(nrIT, stadsetningIT)) {
                    errorMsg("Fann ekki búnað með númerið: " + to_string(nrIT));
                }
            } else if (tegund == "numer") {
                ss >> nrIT >> nr2IT;
                if (!hg.uppfaeraIndex(nrIT, nr2IT)) {
                    errorMsg("Fann ekki búnað með númerið: " + to_string(nrIT));
                }
            } else if (tegund == "verd") {
                ss >> nrIT >> verdIT;
                if (!hg.uppfaeraVerd(nrIT, verdIT)) {
                    errorMsg("Fann ekki búnað með númerið: " + to_string(nrIT));
                }
            } else {
                errorMsg("Skil ekki skipuninna " + tegund);
            }
        } else if (skipun == "haetta") {
            setColor(GREEN);
            cout << "\nTakk fyrir\n";
            setColor(WHITE);
            ofstream skrifa("lokaverkefni/saves/" + path);
            if (!skrifa) {
                errorMsg("gat ekki opnað skrá");
            } else {
                skrifa << hg.ollGognIStreng();
            }
            skrifa.close();
        } else {
            errorMsg("Skil ekki skipuninna " + skipun);
        }
        
    cout << "\n";
    } while (skipun != "haetta");

    resetColor();
    return 0;
}