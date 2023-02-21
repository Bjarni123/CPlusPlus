#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int main() {

    int fylki[][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    int* pf = fylki[0][0];
    int* bp = pf;

    cout << sizeof(fylki) << "\n"; // 32
    cout << sizeof(fylki[0]) << "\n"; // 16
    cout << sizeof(fylki[0][0]) << "\n"; // 8
    cout << sizeof(fylki[0][0][0]) << "\n"; // 4
    cout << "\n";


    /* 
    int fjoldiStakaIYtraFylki = sizeof(fylki) / sizeof(fylki[0]);
    int fjoldiStakaIMidjuFylki = sizeof(fylki[0]) / sizeof(fylki[0][0]);
    int fjoldiStakaIInnraFylki = sizeof(fylki[0][0]) / sizeof(fylki[0][0][0]);

    for (int i = 0; i < fjoldiStakaIYtraFylki; i++) {
        for (int j = 0; j < fjoldiStakaIMidjuFylki; j++) {
            for (int k = 0; k < fjoldiStakaIInnraFylki; k++) {
                cout << "value: " << fylki[i][j][k] << " Address: " << &fylki[i][j][k] << "\n";
            }
        }
    } */

    int fjoldiStakaIFylki = sizeof(fylki) / sizeof(fylki[0][0][0]);
    pf = bp;
    for (int i = 0; i < fjoldiStakaIFylki; i++) {
        cout << *pf << "\n";
        *pf++;
    }

    return 0;
}