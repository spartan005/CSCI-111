// Filename: file_output.cpp
// Author: Bobby Teenager
// Date: 17 Sep 2014
//
// Reads in the data from two people from a file
// Prints the data out to the screen
//
#include<iostream>
#include<fstream>
using namespace std;
int main()
{

  string name1, name2;
  int age1, age2;
  float gpa1, gpa2;

  ifstream inf;
  inf.open("data.txt");
  if( !inf.is_open() )
  {
    cerr << "Can't open data.txt! Have you written out the file yet?" << endl;
    return 1;
  }
  
  getline(inf, name1, '|');
  inf >> age1;
  inf.ignore();
  inf >> gpa1;
  inf.ignore();
  //###
  getline(inf, name2, '|');
  inf >> age2;
  inf.ignore();
  inf >> gpa2;
  inf.ignore();

  inf.close();

  cout << "Person 1 name: " << name1 << endl;
  cout << "Person 1 age: " << age1 << endl;
  cout << "Person 1 GPA: " << gpa1 << endl;
  cout << "---" << endl;
  cout << "Person 2 name: " << name2 << endl;
  cout << "Person 2 age: " << age2 << endl;
  cout << "Person 2 GPA: " << gpa2 << endl;

  return 0;
}
