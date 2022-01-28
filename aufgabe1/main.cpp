#include <iostream>

using namespace std;

int ggt(int a, int b) {
    int rest;

    do {
        rest = a % b;
        a = b;
        b = rest;
    } while (rest != 0);
    return a;
}


void menu() {
    int a, b, ergebnis;

    cout << "Erste Zahl:\n";
    cin >> a;
    cout << "Zweite Zahl:\n";
    cin >> b;
    ergebnis = ggt(a,b);
    cout << "Der ggT der Zahlen " << a << " und " << b << " ist: " << ergebnis << endl;
}


int main() {

    menu();

    return 0;
}