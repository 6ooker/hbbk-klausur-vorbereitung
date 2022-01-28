#include <iostream>

using namespace std;

/**
 * @brief Ermittelt die Anzahl von Teilern einer Zahl.
 * Jede Zahl hat mindestens zwei Teiler: 1 und sich selbst.
 * 
 * @param num Zahl != 0, für welche die AvT ermittelt wird.
 * @return int Die AvT der Zahl, immer min. 2
 */
int avt(int num) {
    if (num == 0) {
        cerr << "Die eingabe '0' ist unzulässig!\n";
        exit(EXIT_FAILURE);
    }

    int counter = 0;

    for(int i = 1; i <= num; i++) {
        if (num % i == 0) {
            counter++;
        }
    }

    return counter;
}


void hoechste_avt_bis_x(int max) {
    int hoechste_avt = 0;
    int zahl_mit_meisten_teilern = 0;

    for (int i = 2; i <= max; i++) {
        int avt_von_x = avt(i);

        if ( avt_von_x > hoechste_avt) {
            hoechste_avt = avt_von_x;
            zahl_mit_meisten_teilern = i;
        }
    }

    cout << "Die Zahl mit der höchsten Anzahl von Teilern ist: " << zahl_mit_meisten_teilern << " mit " << hoechste_avt << " Teilern!\n";
}


void menu_1() {
    int a, ergebnis;

    cout << "Geben Sie eine Zahl ein:\n";
    cin >> a;
    ergebnis = avt(a);
    cout << "Die " << a << " hat " << ergebnis << " Teiler.\n";
}


int main() {

    

    return 0;
}