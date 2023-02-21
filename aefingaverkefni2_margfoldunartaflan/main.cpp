#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int count_digit(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

void prentaToflu(int *pf,  int radir, int dalkar) {
    cout << "    |    ";
    for (int i = 0; i < dalkar; i++) {
        cout << i+1 << "\t";
    }
    cout << "\n---";
    for (int i = 0; i < dalkar; i++) {
        cout << "--------";
    }
    cout << "\n    |\n";
    for (int i = 0; i < radir; i++) {
        cout << i+1;
         for (int j = 0; j < (4 - (count_digit(i + 1))); j++) {
            cout << " ";
        }
        cout << "|    ";
        for (int j = 0; j < dalkar; j++) {
            cout << *pf << "\t";
            pf++;
        }
        cout << "\n    |\n";
    }
}

int main() {
    // [radir][dalkar]
    int tafla[10][10] = {{0}};
    int *pf = tafla[0];

    int fjoldiStakaIYtraFylki = sizeof(tafla) / sizeof(tafla[0]);
    int fjoldiStakaIInnraFylki = sizeof(tafla[0]) / sizeof(tafla[0][0]);

    for (int i = 0; i < fjoldiStakaIYtraFylki; i++) {
        for (int j = 0; j < fjoldiStakaIInnraFylki; j++) {
            tafla[i][j] = (i+1) * (j+1);
        }
    }
    prentaToflu(pf, sizeof(tafla) / sizeof(tafla[0]), sizeof(tafla[0]) / sizeof(tafla[0][0]));

    return 0;
}