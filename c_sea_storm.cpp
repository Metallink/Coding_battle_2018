//
// Created by Sameh EL AWADI  on 19/10/2018.
//
#include <string>
#include <iostream>
#include <vector>

int factorial (int n);

int main() {

    int longueurPont(0), nbPosition(0), combinaisonPossible(0);

    cin >> longueurPont >> nbPosition;

    combinaisonPossible = factorial(nbPosition);

    vector<int> posteCombat(nbPosition);
    vector<int> tailleChap(nbPosition);
    vector<int> position(longueurPont);

    for (int i(0); i < nbPosition; i++)
        cin >> posteCombat[i];

    for (int j(0); j < nbPosition; j++)
        cin >> tailleChap(nbPosition);

    for (int k(0); k < combinaisonPossible; k++) {


    }


// 4 1 2 ++ 0
// 2 4 1 ++ 1
// 1 2 4 ++ 2
//

// 4 2 1
// 1 2 4
// 1 4 2
// 2 1 4
// 2 4 1

    return 0;
}

int factorial (int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


