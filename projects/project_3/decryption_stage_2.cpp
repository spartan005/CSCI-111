// James Oppy, Project 3 part 2
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string normalize_sentence(string message)
{
  transform (message.begin(), message.end(), message.begin(), ::tolower);
  return message;
}

int main()
{
  string message;
  ifstream decode;
  ofstream stage3;
  decode.open("stage2.txt");
  getline (decode, message);
  message = normalize_sentence(message);
  decode.close();
  stage3.open("stage3.txt");
  stage3 << message;
  stage3.close();

  return 0;
}
