// James Oppy, decrypt.cpp
#include<iostream>
#include<string>
#include "Machine.h"
using namespace std;

int main()
{
  string s = "";
  long int c;
  Machine x;
  cout << "Enter the code to be decrypted, press <Ctrl> + <D> when finished." << endl;
  while (!(cin >> c).eof()) { 
    s += x.decrypt(c);
  }
  cout << endl << endl << "The decrypted message is:" << endl << s << endl;

  return 0;
}
