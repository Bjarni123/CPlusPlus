#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int main() {

    int fylki[] = {5, 1, 4, 8, 11};
    double dfylki[] = {1.1, 2.2, 3.3};
    double *dpf = dfylki;
    int* pf = fylki;
    int* bp = pf;

    cout << pf << "\n";

    pf = bp;
    cout << "For lykkjan: \n";
    for (int i = 0; i < sizeof(fylki) / sizeof(fylki[0]); i++) {
        cout << *pf << "\n";
        *pf++;
    }

    return 0;
}