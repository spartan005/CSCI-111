// James Oppy, Machine.h
#ifndef MACHINE_H
#define MACHINE_H
#include<vector>
#include "Rotor.h"
using namespace std;

class Machine {
  private:
    vector<Rotor> spindle;
  public:
    Machine();
    long int encrypt(char ch);
    char decrypt(long int e);
};
#endif
