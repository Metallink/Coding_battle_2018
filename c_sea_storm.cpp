//
// Created by Sameh EL AWADI  on 19/10/2018.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "c_sea_storm.h"
using namespace std;

void seaStorm() {

    int longueurPont(0), nbPosition(0), minRangDelta(0), maxRangDelta(0);

    cin >> longueurPont >> nbPosition;

    vector<int> posteCombat(nbPosition, 0);
    vector<int> tailleChap(nbPosition, 0);
    vector<int> position(longueurPont, 0);

    for (int i(0); i < nbPosition; i++)
        cin >> posteCombat[i];

    for (int j(0); j < nbPosition; j++)
        cin >> tailleChap[j];

    // sort hat's wide in ascent order
    sort(tailleChap.begin(), tailleChap.end());

    for (int k(0); k < nbPosition; k++)
        position[posteCombat[k]-1] = 1;

    // *****************************************

    // on va chercher à déterminer le MIN et MAX de deltaMax
    deltaMax(posteCombat, minRangDelta, maxRangDelta);
    minRangDelta = posteCombat[minRangDelta]-1;
    maxRangDelta = posteCombat[maxRangDelta]-1;
    //    cout << "MIN Index: " << minRangDelta << endl; //== 1
    //    cout << "MAX Index: " << maxRangDelta << endl; //== 2

    // get the widest hat
    int taillePlusGrandChapeau = tailleChap[tailleChap.size()-1];
    //cout << "Taille du + gd chap: " << taillePlusGrandChapeau << endl;

    // si max est tout à droite
    if (maxRangDelta+1 == position.size()) {
        //cout << "CA MARCHE" << endl;
        placerChapeauGauche(position, maxRangDelta, taillePlusGrandChapeau); // 2.1.2
        placerChapeauMin(position, minRangDelta, maxRangDelta, tailleChap);
    }

//    cout << "TABLEAU APRES PLACEMENT CHAPEAU" << endl;
//    for (int a(0); a < position.size(); a++)
//        cout << position[a] << ' ';


//    while (posteCombat.size() > 0) {
//
//
//    }

    // 1. on cherche le rang du deltamax
    // 2. on fait (nbPosteCombat - 1) / 2: // tant que
    //  2.1 si max = extremite alors
    //      2.1.1 on cherche le max
    //      2.1.2 on place le chapeau max à la position du MAX de deltamax
    //      2.1.3 on essaie de placer le chapeau de la plus petite taille possible au MIN de deltamax
    //      2.1.4 on vérifie si le deltamax est couvert
    //          2.1.4.1 on renvoi false si ce n'est pas le cas
    //  2.2 si au milieu alors
    //      2.2.1 on cherche le max
    //      2.2.2 on place le chapeau max à la position du MAX de deltamax
    //          2.2.2.1 on rempli le deltamax
    //          2.2.2.2 on rempli le côte opposé
    //      2.2.3 on essaie de placer le chapeau de la plus petite taille possible au MIN de deltamax
    //      2.2.4 on vérifie si le deltamax est couvert
    //          2.1.4.1 on renvoi false si ce n'est pas le cas



}

void deltaMax(vector<int>& posteCombat, int& min, int& max) {
    int result(0);
    for (int z(posteCombat.size()-1); z >= 0; z--) {
        if ((posteCombat[z] - posteCombat[z-1]) > result) {
            result = posteCombat[z] - posteCombat[z-1];
            max = z ;
            min = z - 1;
        }
    }
}


void placerChapeauGauche(vector<int>& tPosition, int iPosition, int tailleChap) {

    for (int i(iPosition); i >= iPosition - tailleChap; --i) {
        tPosition[i] = 1;
    }
}

void placerChapeauDroite(vector<int>& tPosition, int iPosition, int tailleChap) {

    for (int i(iPosition+1); i <= iPosition + tailleChap; ++i) {
        tPosition[i] = 1;
    }
}

bool isProtected (vector<int>& tPosition, int min, int max) {
    for (int i(min+1); i < max; i++) {
        if (tPosition[i] == 0)
            return false;
    }
    return true;
}

void placerChapeauMin (vector<int>& tPosition, int iMin, int iMax, vector<int>& tChapeau) {

    int iTabChap(0), tailleChap(0);
    while (iTabChap < tChapeau.size()-1) {

        tailleChap = tChapeau[iTabChap];
        placerChapeauDroite(tPosition, iMin, tailleChap);
        /*cout << "MIN= " << iTabChap << endl;
        for (int a(0); a < tPosition.size(); a++)
            cout << tPosition[a] << ' ';
        cout << endl;*/
        if (isProtected(tPosition, iMin, iMax)){
            //tChapeau.pop_back()
            break;
        }
        iTabChap++;
    }
}



