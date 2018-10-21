//
// Created by Sameh EL AWADI  on 19/10/2018.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "c_sea_storm.h"
using namespace std;


// the idea here is to find the longest length between 2 pirates and start deploying using the right size from the right to the left.
bool seaStorm() {
    int len(0), nbPosition(0), minDelta(0), maxDelta(0);

    cin >> len >> nbPosition;

    vector<int> tCombatPost(nbPosition, 0);
    vector<int> tHatSize(nbPosition, 0);
    vector<int> tPosition(len, 0);

    // filling the vectors
    for (int i(0); i < nbPosition; i++)
        cin >> tCombatPost[i];
    for (int j(0); j < nbPosition; j++)
        cin >> tHatSize[j];
    // sort hat's wide in ascent order
    sort(tHatSize.begin(), tHatSize.end());

    for (int k(0); k < nbPosition; k++)
        tPosition[tCombatPost[k]-1] = 1;

    // easiest situation: one pirate is covering
    if (nbPosition == 1) {
        // the pirate is standing on the first spot (left side of the ship)
        if ((tCombatPost[0]-1) == 0) {
            setHatsRight(tPosition, tCombatPost[0]-1, tHatSize[0]); // deploying his hat towards the right
        } else if ((tCombatPost[0]-1) == len){ // the pirate is standing on the last spot (right side of the ship)
            setHatsLeft(tPosition, tCombatPost[0]-1, tHatSize[0]); // deploying his hat towards the left
        } else { // the pirate is somewhere in the middle
            // deploying both side
            setHatsLeft(tPosition, tCombatPost[0]-1, tHatSize[0]);
            setHatsRight(tPosition, tCombatPost[0]-1, tHatSize[0]);
        }
        // we check if he's protecting the whole ship
        return isProtected(tPosition, 0, tPosition.size());
    }

    while (true) { // starting from right to left, while we didn't reach the first position (left side)
        // not a duplication but we got to check the last man covering
        if (nbPosition == 1) {
            if ((tCombatPost[0]-1) == 0) {
                setHatsRight(tPosition, tCombatPost[0]-1, tHatSize[0]);
            } else if ((tCombatPost[0]-1) == len){ //si max est tout à droite
                setHatsLeft(tPosition, tCombatPost[0]-1, tHatSize[0]);
            } else {
                setHatsLeft(tPosition, tCombatPost[0]-1, tHatSize[0]);
                setHatsRight(tPosition, tCombatPost[0]-1, tHatSize[0]);
            }
            return isProtected(tPosition, 0, tPosition.size());
        }
        // finding the longest length separating two pirates starting from the right side
        deltaMax(tCombatPost, minDelta, maxDelta);
        minDelta = tCombatPost[minDelta]-1; // index of the pirate nb 1
        maxDelta = tCombatPost[maxDelta]-1; // index of the pirate nb 2
        // widest hat
        int widestHat = tHatSize[tHatSize.size()-1];

        // case of pirate nb 2 standing on the last position (right side of the ship)
        if (maxDelta+1 == tPosition.size()) {
            setHatsLeft(tPosition, maxDelta, widestHat); // deploying towards left
            // we try to deploy the pirate nb 1's hat using first from the smallest to the biggest hat available
            if (!settingRightHatSize(tPosition, tHatSize, tCombatPost, minDelta, maxDelta))
                return false; // the ship is unprotected :c
            else {
                if (isProtected(tPosition, 0, tPosition.size())) // checking the whole ship
                    return true; // the ship is protected !
            }
        } else if (maxDelta == 0){ // the pirate nb 2 is standing on the first position (left side)
            setHatsRight(tPosition, 0, widestHat); // deploying the hat towards the right
            return isProtected(tPosition, 0, tPosition.size()); // we never know
        } else { // otherwise pirate nb 2 is standing somewhere in the middle
            setHatsLeft(tPosition, maxDelta, widestHat);
            setHatsRight(tPosition, maxDelta, widestHat);
            if (!isProtected(tPosition, maxDelta, tPosition.size()))
                return false; // if the position at the right side of the pirate nb 2 aren't covered then the ship isn't covered
            if (!settingRightHatSize(tPosition, tHatSize, tCombatPost, minDelta, maxDelta))
                return false;
            else {
                if (isProtected(tPosition, 0, tPosition.size()))
                    return true;
            }
        }
    }
}

void deltaMax(vector<int>& tCombatPost, int& min, int& max) {
    int result(0);
    if (tCombatPost.size() == 1) { // last position unchecked
        max = 0;
        min = 0;
    }
    else if (tCombatPost.size() == 2) { // 2 positions remaining
        min = 0;
        max = 1;
    } else {
        for (int z(tCombatPost.size()-1); z >= 0; z--) {
            if ((tCombatPost[z] - tCombatPost[z-1]) > result) {
                result = tCombatPost[z] - tCombatPost[z-1];
                max = z;
                min = z - 1;
            }
        }
    }
}

void setHatsLeft(vector<int>& tPosition, int iPosition, int tHatSize) {
    for (int i(iPosition-1); i >= iPosition - tHatSize; --i)
        tPosition[i] = 1;
}

void setHatsRight(vector<int>& tPosition, int iPosition, int tHatSize) {
    for (int i(iPosition+1); i <= iPosition + tHatSize; ++i)
        tPosition[i] = 1;
}

bool isProtected (vector<int>& tPosition, int min, int max) {
    for (int i(min+1); i < max; i++) {
        if (tPosition[i] == 0) // if we find a single position uncovered
            return false;
    }
    return true;
}

bool settingRightHatSize (vector<int>& tPosition, vector<int>& tHat, vector<int>& tCombatPost, int iMin, int iMax) {
    int iTabHat(0), tHatSize(0);
    while (iTabHat < tHat.size()-1) { // from the first size to the second to last size

        tHatSize = tHat[iTabHat];
        setHatsRight(tPosition, iMin, tHatSize);

        if (isProtected(tPosition, iMin, iMax)){
            setHatsLeft(tPosition, iMin, tHatSize); // if it covers the right size, it's worth to deploy towards the left side
            if (tCombatPost.size() >= 3) { // there was 3 positions unchecked (we checked 2 of them)
                tHat.pop_back();
                tHat.pop_back();
                tCombatPost.pop_back();
                tCombatPost.pop_back();
            } else if (tCombatPost.size() == 2){ // The size of a vector tab cannot be 0
                tHat.pop_back();
                tCombatPost.pop_back();
                tHat.pop_back();
                tCombatPost.pop_back();
            }
            return true;
        }
        iTabHat++;
    }
    return false;
}