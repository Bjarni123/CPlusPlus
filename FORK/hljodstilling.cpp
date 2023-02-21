#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, l, k;
    if (!(cin >> r >> l >> k)) {
        cerr << "Error: Invalid input format." << endl;
        return 1;
    }

    vector<int> favNumbers(k);
    for (int i = 0; i < k; i++) {
        if (!(cin >> favNumbers[i])) {
            cerr << "Error: Invalid input format." << endl;
            return 1;
        }
    }

    int counter = 0;
    for (int x = r; x <= l; x++) {
        for (int y : favNumbers) {
            if (x % y == 0) {
                counter++;
                break;
            }
        }
    }

    cout << counter << endl;
    return 0;
}
