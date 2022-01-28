#include <iostream>

using namespace std;

/**
 * @brief Zerlegt eine Zahl >1 in ihre Primfaktoren. Gibt diese anschließend aus.
 * 
 * @param zahl Zahl > 1
 */
void prim_faktoren(int zahl) {
    int faktor = 2;

    while (zahl >= 2) {

        while (zahl % faktor == 0) {

            zahl /= faktor;
            cout << faktor;
            if (zahl >= 2) {
                cout << "*";
            }
        }

        faktor++;
    }


}


void menu() {
    int zahl;

    cout << "Geben Sie eine Zahl >1 ein:\n";
    cin >> zahl;
    cout << "Primfaktoren:  " << zahl << " = ";
    prim_faktoren(zahl);
    cout << endl;
}


int main() {

    menu();

    return 0;
}