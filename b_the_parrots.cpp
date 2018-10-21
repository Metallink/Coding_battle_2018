//
// Created by Sameh EL AWADI on 19/10/2018.
//

#include "b_the_parrots.h"
#include <string>
#include <iostream>

using namespace std;

void parrot() {
    int budget (0), nombre(0), prix(0), commission(0), nbPerroquet(0), maxPerroquet(0);
    string nomDresseur, meilleurDresseur;

    cin >> budget >> nombre;

    for (int i(0); i < nombre; i++) {

        cin >> nomDresseur >> prix >> commission;

        nbPerroquet = (budget - commission) / prix;

        if (maxPerroquet < nbPerroquet) {

            meilleurDresseur = nomDresseur;
            maxPerroquet = nbPerroquet;
        }
    }

    if (maxPerroquet == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << maxPerroquet << endl;
        cout << meilleurDresseur;
    }
}
