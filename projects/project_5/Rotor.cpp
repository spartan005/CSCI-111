// James Oppy, Rotor.cpp
#include "Rotor.h"

Rotor::Rotor(short int m, short int a) : multiplier(m), adder(a)
{
}

long int Rotor::encode(long int w)
{
  return (w * multiplier + adder);
}

long int Rotor::decode(long int s)
{
  return ((s - adder) / multiplier);
}
