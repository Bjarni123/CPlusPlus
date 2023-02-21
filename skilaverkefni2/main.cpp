#include <iostream>
#include <string>
#include <iomanip>

#include "nemandi.h"
#include "afangi.h"

using namespace std;

int main() {
    Nemandi geir = Nemandi("Geir");
    geir.skraIAfanga(33, "GAGN", 2.43);

    Afangi forr(34, "FORR", 3.59);
    geir.skraIAfanga(forr);
    geir.prentaAfanga(34); // ætti að skrifa út:
                          // ID: 34, nafn: FORR, einkunn: 3.59
    
    geir.skraIAfanga(35, "ROBO", 10);
    geir.skraIAfanga(36, "KEST", 6.249);

    //            áfangi_id, einkunn
    geir.uppfaeraEinkunn(34, 4.49);

    //       áfangi_id
    geir.eydaAfanga(33);

    geir.prentaAllaAfanga(); // ætti að skrifa út:
                   //   Nemandi: Geir, áfangar:
                   //   ID: 34, nafn: FORR, einkunn: 4.49
                   //   ID: 35, nafn: ROBO, einkunn: 10.00
                   //   ID: 36, nafn: KEST, einkunn: 6.25
                   //   Meðaleinkunnin er 6.91
                    
    return 0;
}