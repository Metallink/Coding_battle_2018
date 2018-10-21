//
// Created by Sameh EL AWADI on 19/10/2018.
//

#ifndef CODINGBATTLE_C_SEA_STORM_H
#define CODINGBATTLE_C_SEA_STORM_H

#include <vector>

bool seaStorm();
void deltaMax(std::vector<int>& posteCombat, int& min, int& max);
void setHatsLeft(std::vector<int>& tPosition, int maxIndex, int tailleChap);
void setHatsRight(std::vector<int>& tPosition, int iPosition, int tailleChap);
bool settingRightHatSize (std::vector<int>& tPosition, std::vector<int>& tHat, std::vector<int>& tCombatPost, int iMin, int iMax);
bool isProtected (std::vector<int>& tPosition, int min, int max);

#endif //CODINGBATTLE_C_SEA_STORM_H
