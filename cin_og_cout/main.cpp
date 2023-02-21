#include <iostream>
#include <string>

using namespace std;

int main() {
    string texti;
    cout << "Sláðu inn texta: ";
    getline(cin, texti); // cin >> texti
    cout << "Þú slóst inn: " << texti << "!\n";
    int inntak, a;
    float b;
    char c;
    cout << "Sláðu inn fjórar tölur: ";
    cin >> inntak >> a >> b >> c;
    int summa = inntak + a + b + c;
    cout << "Summa talnanna er: " << summa << "!\n";
    return 0;
}