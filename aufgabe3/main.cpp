#include <iostream>

using namespace std;


int f_datum_erster_freitag(int startwochentag) {
    
    int datum_erster_freitag = 0;
    
    switch (startwochentag) {
        case (1): datum_erster_freitag = 5;
        break;
        case (2): datum_erster_freitag = 4;
        break;
        case (3): datum_erster_freitag = 3;
        break;
        case (4): datum_erster_freitag = 2;
        break;
        case (5): datum_erster_freitag = 1;
        break;
        case (6): datum_erster_freitag = 7;
        break;
        case (7): datum_erster_freitag = 6;
        break;
        default: cerr << "Fehler bei Datum des ersten Freitags!\n";
    }
    return datum_erster_freitag;
}

int f_tage_pro_monat(int monat, int schaltjahr) {
    int m31t[7] = { 1, 3, 5, 7, 8, 10, 12 };
    int m30t[4] = { 4, 6, 9, 11 };

    // Monate 31 Tage:
    for (int i = 0; i < 7; i++) {
        if (monat == m31t[i]) {
            return 31;
        }
    }

    // Monate 30 Tage:
    for (int j = 0; j < 4; j++) {
        if (monat == m30t[j]) {
            return 30;
        }
    }

    // Sonderregelung Februar:
    if (monat == 2 && schaltjahr == 1) {
        return 29;
    }
    else if (monat == 2 && schaltjahr == 0) {
        return 28;
    }
    else {
        cerr << "Fehler bei Tage pro Monat!\n";
        exit(EXIT_FAILURE);
    }

}

void freitag(int wochentag, int schaltjahr) {
    /* Montag = 1, Dienstag = 2, Mittwoch = 3, Donnerstag = 4, Freitag = 5, Samstag = 6, Sonntag = 7
     * Schaltjahr = 1, Kein Schaltjahr = 0
     */
    int start = f_datum_erster_freitag(wochentag);

    // Monate durchgehen:
    for (int monat = 1; monat <= 12; monat++) {

        
        // Freitage Daten zuweisen:
        int tage_pro_monat = f_tage_pro_monat(monat, schaltjahr);

        for (int i = start; i <= tage_pro_monat; i += 7) {
            if (i == 13) {
                cout << " " << monat << ". "; // Der Output für die Zahl der Monate mit Freitag der 13.
            }

            if (i + 7 > tage_pro_monat) { // Wrap around für Datum des nöchsten Freitags im nächsten Monat
                start = ( i + 7 ) - tage_pro_monat;
                break;
            }
        }
    }
}


void freitag_alle_jahrestypen() {
    
    for (int schaltjahr = 0; schaltjahr <= 1; schaltjahr++) {
        
        for (int wochentag = 1; wochentag <= 7; wochentag++) {

            cout << "Start-Wochentag: " << wochentag << " Schaltjahr: " << schaltjahr << endl;
            freitag(wochentag, schaltjahr);
            cout << endl;
        }
    }
}



void hauptmenu_freitag() {

    int tag, schaltjahr;

    cout << "Geben Sie an, mit welchem Wochentag das Jahr beginnt.\n[1] Montag, [2] Dienstag, [3] Mittwoch, [4] Donnerstag, [5] Freitag, [6] Samstag, [7] Sonntag\n";
    cin >> tag;
    cout << "Geben Sie nun an, ob es sich um ein Schaltjahr handelt, oder nicht.\n[1] Ja, [0] Nein\n";
    cin >> schaltjahr;
    
    cout << "In einem Jahr, welches mit einem ";
    switch (tag) {
        case (1): cout << "Montag ";
        break;
        case (2): cout << "Dienstag ";
        break;
        case (3): cout << "Mittwoch ";
        break;
        case (4): cout << "Donnerstag ";
        break;
        case (5): cout << "Freitag ";
        break;
        case (6): cout << "Samstag ";
        break;
        case (7): cout << "Sonntag ";
        break;
    }
    cout << "beginnt und welches ";
    switch (schaltjahr) {
        case (1): cout << "ein ";
        break;
        case (0): cout << "kein ";
        break;
    }
    cout << "Schaltjahr ist fallen in folgenden Monaten der 13. auf einen Freitag:\n";
    freitag(tag, schaltjahr);
}


int main() {

    hauptmenu_freitag();
    //freitag_alle_jahrestypen();
    return 0;
}