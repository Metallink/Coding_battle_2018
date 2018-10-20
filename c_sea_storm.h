//
// Created by Sameh EL AWADI on 19/10/2018.
//

#ifndef CODINGBATTLE_C_SEA_STORM_H
#define CODINGBATTLE_C_SEA_STORM_H

#include <vector>

void seaStorm();
void deltaMax(std::vector<int>& posteCombat, int& min, int& max);
void placerChapeauGauche(std::vector<int>& tPosition, int maxIndex, int tailleChap);
void placerChapeauDroite(std::vector<int>& tPosition, int iPosition, int tailleChap);
void placerChapeauMin (std::vector<int>& tPosition, int iMin, int iMax, std::vector<int>& tChapeau);
bool isProtected (std::vector<int>& tPosition, int min, int max);

#endif //CODINGBATTLE_C_SEA_STORM_H
