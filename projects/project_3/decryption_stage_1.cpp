#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string reverse_sentence(string message)
{
  reverse (message.begin(), message.end());
  return message;
}

int main()
{
  string message;
  ifstream decode;
  ofstream stage2;
  decode.open("one_message.txt");
  getline (decode, message);
  message = reverse_sentence(message);
  decode.close();
  stage2.open("stage2.txt");
  stage2 << message;
  stage2.close();

  return 0;
}
