// Filename: file_output.cpp
// Author: Bobby Teenager
// Date: 17 Sep 2014
//
// Asks a user for data on two people.
// Writes the data out to a file
//
#include<iostream>
#include<fstream>
using namespace std;
int main()
{

  string name1, name2;
  int age1, age2;
  float gpa1, gpa2;
  cout << "We need information for two people" << endl;
  cout << "What is the first person's name? " << endl;
  getline(cin, name1);
  cout << "How old is the first person? " << endl;
  cin >> age1;
  cout << "What is the GPA of the first person? " << endl;
  cin >> gpa1;
  cout << "---" << endl;
  //###
  cout << "What is the second person's name? " << endl;
  cin.ignore(); //ignore the newline the user typed when hitting the enter key
  getline(cin, name2);
  cout << "How old is the second person? " << endl;
  cin >> age2;
  cout << "What is the GPA of the second person? " << endl;
  cin >> gpa2;

  ofstream outf;
  outf.open("data.txt");
  if( !outf.is_open() )
  {
    cerr << "Can't open data.txt! I'm so ashamed." << endl;
    return 1;
  }

  outf << name1 << '|';
  outf << age1 << '|';
  outf << gpa1 << endl;
  outf << name2 << '|';
  outf << age2 << '|';
  outf << gpa2 << endl;

  outf.close();

  return 0;
}
