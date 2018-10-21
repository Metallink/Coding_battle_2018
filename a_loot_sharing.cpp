//
// Created by Sameh EL AWADI on 21/10/2018.
//

#include <iostream>
#include <string>
using namespace std;

void loot() {

  int b(0), t(0), n(0);

  cin >> b >> t >> n;

  if ((b*2+t*3) <= n)
    cout << "LOOT!" << endl;
  else
    cout << "RHUM!" << endl;
}
