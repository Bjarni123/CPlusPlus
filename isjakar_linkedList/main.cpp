#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

#include "isjakarRadad.h"

int main() {

    IsjakarRadad ir;

    Isjaki j1 = Isjaki(10, 20, 30);
    ir.skraIsjaka(j1);
    ir.skraIsjaka(11, 20, 29);
    ir.skraIsjaka(12, 50, 29);
    ir.skraIsjaka(13, 40, 29);
    ir.skraIsjaka(14, 10, 29);
    ir.skraIsjaka(99, 20, 29);

    ir.prentaAllt();


    int id = 99;
    if(ir.eydaIsjaka(id)) {
        cout << "Eyddi ísjaka nr. " << id << "\n";
    } else {
        cout << "Fann ekki ísjaka nr. " << id << "\n";
    }

    return 0;
}