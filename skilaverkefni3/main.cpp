#include <iostream>
#include <string>
#include <iomanip>

#include "linkedList.h"

using namespace std;

int main() {

    LinkedList ll;

    cout << "Skrái Umsækjendur.\n";
    Umsaekjandi umsaekjandi1 = Umsaekjandi("Robin", 18, 7.2);
    ll.skraUmsaekjanda(umsaekjandi1);
    ll.skraUmsaekjanda("Jamie", 16, 7.4);
    ll.skraUmsaekjanda("Kyson", 57, 10);
    ll.skraUmsaekjanda("Emmy", 15, 5.4);
    ll.skraUmsaekjanda("Birgir", 15, 3.5);
    ll.skraUmsaekjanda("Amani", 19, 6.4);
    ll.skraUmsaekjanda("Bjarni", 18, 10);

    cout << "\nPrenta alla umsækjendur:\n";
    ll.prentaAllt();

    cout << "\nPrenta út einn umsækjanda.\n";
    ll.prentaEinnUmsaekjanda("Kyson");

    cout << "\nSæki besta umsækjanda og set hann í jatadInnISkolann breytuna.\n";
    Umsaekjandi jatadInnISkolann = ll.saekjaNaesta();
    cout << jatadInnISkolann << "\n";

    cout << "\nEyði Bjarni umsækjandanum út.\n";
    string nafn = "Bjarni";
    if(ll.eydaUmsaekjanda(nafn)) {
        cout << "Eyddi umsækjandanum: " << nafn << "\n";
    } else {
        cout << "Fann ekki umsækjandan: " << nafn << "\n";
    }

    cout << "\nPrenta alla aftur út eftir að eyða umsækjanda.\n";
    ll.prentaAllt();

    return 0;
}