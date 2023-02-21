#include <iostream>
#include <string>
#include <iomanip>

#include "Bill.h"

using namespace std;

int main() {
    Bill b;
    b.prenta();
    Bill toyota = Bill(11, "Toyota", "Rauður");
    Bill bmw = Bill(12, "BMW", "Grænn");
    cout << toyota.toString() << "\n";
    toyota.setLitur("Blár");
    toyota.prenta();


    // if(toyota.erEins(bmw))

    if(toyota > bmw) {
        cout << "Toyotan er stærri en BMW-inn\n";
    }
    else {
        cout << "Toyotan er minni eða sama sem BMW-inn\n";
    }
    if (toyota == bmw) {
        cout << "Toyotan er eins og BMW-inn\n";
    }
    else {
        cout << "Toyotan er ekki eins og BMW-inn\n";

    }
    cout << bmw << " " << toyota << " Geir " << "\n";

    return 0;
}