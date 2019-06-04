// James Oppy, Rotor.h
#ifndef ROTOR_H
#define ROTOR_H

//Rotor class declaration
class Rotor {
  private:
    short int multiplier;
    short int adder;
  public:
    Rotor(short int m, short int a);
    long int encode(long int w);
    long int decode(long int s);
};
#endif
