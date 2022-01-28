#include <iostream>

using namespace std;


void hoppla() {
    
    for (int i = 1; i <= 99; i++) {
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7) {
            cout << "hoppla\n";
        }
        else {
            cout << i << endl;
        }
    }
}


int main() {

    hoppla();

    return 0;
}