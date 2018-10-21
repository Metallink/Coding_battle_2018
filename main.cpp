#include <iostream>
#include <string>
#include "b_the_parrots.h"
#include "c_sea_storm.h"

using namespace std;

int main() {

    int choix(0), stop(0);
    cout << "================== CODING BATTLE ==================" << endl;
    cout << "Choose your exercice || press 9 to exit " << endl;
    cin >> choix;

    while (!stop) {
        switch (choix) {
            case 1 :
                break;
            case 2 :
                parrot();
                break;
            case 3 :
                cout << (seaStorm() ? "YES" : "NO") << endl;
                break;
            case 0:
                cout << "Bye !" << endl;
                stop = 1;
            default:
                cout << "Wrong input, please try again" << endl;
                break;
        }
    }
    return 0;
}