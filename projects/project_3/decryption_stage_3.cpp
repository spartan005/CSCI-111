// James Oppy, Project 3 part 3
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string replace_sentence(string message)
{
  while (message.find("toaster") != string::npos) {
    message.replace(message.find("toaster"), 7, "Cylon");
  }
  while (message.find("barn") != string::npos) {
    message.replace(message.find("barn"), 4, "Galactica");
  }
  return message;
}

int main()
{
  string message;
  ifstream decode;
  ofstream decrypt;
  decode.open("stage3.txt");
  getline (decode, message);
  message = replace_sentence(message);
  decode.close();
  decrypt.open("decrypted.txt");
  decrypt << message;
  decrypt.close();

  return 0;
}
