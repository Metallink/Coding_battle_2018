#include <iostream>
#include <string>
#include "b_the_parrots.h"
#include "c_sea_storm.h"

using namespace std;

int main() {

    int choix(0);
    cout << "**** CODING BATTLE ****" << endl;
    cout << "Exercice a executer ?" << endl;
    cin >> choix;

    switch (choix) {

        case 1 :
            break;
        case 2 :
            parrot();
            break;
        case 3 :
            seaStorm();
            break;
        default:
            break;
    }

    return 0;
}