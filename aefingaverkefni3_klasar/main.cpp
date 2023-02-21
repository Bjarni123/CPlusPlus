#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

#include "tolvur.h"
#include "talva.h"

using namespace std;

int main() {
    Tolvur t;
    t.skraTolvu(1, "Intel", 16, 500);
    t.skraTolvu(2, "Intel", 16, 500);
    t.skraTolvu(3, "Intel", 16, 500);

    Tolvur t2 = t;
    Tolvur t3;
    t3 = t2 = t;
    t2.skraTolvu(99, "AMD", 16, 1000);
    int a = 10, b = 20, c = 30;
    a = b = c;
    t3.skraTolvu(27, "Intel", 15, 1000);
    cout << "T Listinn\n";
    t.prentaAllarTolvur();
    cout << "T2 Listinn\n";
    t2.prentaAllarTolvur();
    cout << "3 Listinn\n";
    t3.prentaAllarTolvur();

    return 0;
}