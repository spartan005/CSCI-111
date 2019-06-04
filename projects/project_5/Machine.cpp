// James Oppy, Machine.cpp
#include<fstream>
#include "Machine.h"
#include "Rotor.h"
using namespace std;

Machine::Machine()
{
  short int m;
  short int a;
  ifstream values;
  values.open("rotors.txt");
  while (!(values >> m).eof()) {
    values >> a;
    Rotor rotor(m, a);
    spindle.push_back(rotor);
  }
  values.close();
}

long int Machine::encrypt(char ch)
{
  long int c = ch;
  for (int i = 0; i < spindle.size(); i++) {
    c = spindle[i].encode(c);
  }
  return c;
}

char Machine::decrypt(long int e)
{
  for (int i = spindle.size() - 1; i >= 0; i--) {
    e = spindle[i].decode(e);
  }
  return e;
}
