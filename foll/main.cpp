#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void prentaNafn(string);
int leggjaSaman(int, int);
int leggjaSaman(int, int, int);
float leggjaSaman(float, float);
double leggjaSaman(double, double);

int haekkaUmEinn(int a) {
    return a + 1;
}

void haekkaUmEinn(int& a, int& b) {
    a++;
    b++;
}

int main() {
    int k = 10;
    cout << &k << "\n";
    cout << haekkaUmEinn(k) << "\n";
    cout << haekkaUmEinn(10) << "\n";
    cout << k << "\n";
    int a = 10, b = 20;
    haekkaUmEinn(5,6);
    cout << "a: " << a << " b: " << b << "\n";

    return 0;
}

void prentaNafn(string nafn) {
    // Void er fall sem skilar engu(ekt return)
    // notum return til þess að hætta í fallinu snemma

    // þetta og
    if (nafn == "Geir") return;
    cout << "Halló " << nafn << "\n";

    // þetta gerir það sama
    /* if (nafn != "Geir") cout << "Halló " << nafn << "\n"; */
}

int leggjaSaman (int a, int b) {
    return a + b;
}

int leggjaSaman(int a, int b, int c) {
    return a + b + c;
}

float leggjaSaman(float a, float b) {
    return a + b;
}

double leggjaSaman(double a, double b) {
    return a + b;
}