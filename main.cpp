#include <iostream>
#include <string>

using namespace std;

int main() {

    int budget (0), nombre(0), prix(0), commission(0), nbPerroquet(0), maxPerroquet(0);
    string nomDresseur, meilleurDresseur;

    cin >> budget >> nombre;

    for (int i(0); i < nombre; i++) {

        cin >> nomDresseur >> prix >> commission;

        nbPerroquet = (budget - commission) / prix;

        if (maxPerroquet < nbPerroquet) {

            meilleurDresseur = nomDresseur;
            maxPerroquet = nbPerroquet;
            //cout << nomDresseur;
        }
    }

    if (maxPerroquet == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << maxPerroquet << endl;
        cout << meilleurDresseur;
    }
    return 0;
}