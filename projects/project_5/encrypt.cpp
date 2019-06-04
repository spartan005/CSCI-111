// James Oppy, encrypt.cpp
#include<iostream>
#include<string>
#include "Machine.h"
using namespace std;

int main()
{
  string s = "";
  string a;
  Machine x;
  cout << "Enter the text to be encrypted, press <Ctrl> + <D> when finished." << endl;
  while (!cin.eof()) {
    getline(cin, a);
    s += a;
    s += '\n';
  }
  cout << endl << endl << "The encrypted message is:" << endl;
  for (int i = 0; i < s.length(); i++) {
    cout << x.encrypt(s[i]) << " ";
  }
  cout << endl;

  return 0;
}
