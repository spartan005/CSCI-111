// Section 07 Gamma
#include<iostream>
#include<string>
using namespace std;

int main()
{
  // Task 1
  int hi = 0;
  cout << "How many times they want the computer to print Hi" << endl;
  cin >> hi;
  for (hi > 0; hi--;) {
    cout << "Hi" << endl;
  }

  cout << "How many times do you want the computer to print Hi" << endl;
  cin >> hi;
  do {
    cout << "Hi" << endl;
    hi--;
  }	while( hi > 0 );

  cout << "How many times do you want the computer to print Hi" << endl;
  cin >> hi;
  while (hi > 0) {
    cout << "Hi" << endl;
    --hi;
  }

  cout << endl;
  // Task 2
  int count = 10;
  for (count > 0; count--;) {
    cout << count + 1 << endl;
  }
  cout << "Liftoff!" << endl;

  count = 10;
  do {
    count--;
    cout << count + 1 << endl;
  } while (count > 0);
  cout << "Liftoff!" << endl;

  count = 10;
  while (count > 0) {
    count--;
    cout << count + 1 << endl;
  }
  cout << "Liftoff!" << endl;

  // Task 3
  cout << endl;
  string name;
  for (name = ""; name != "Barney";) {
    cout << "What is the name" << endl;
    cin >> name;
  }

  cout << endl;
  name = "";
  do {
    cout << "What is the name" << endl;
    cin >> name;
  } while (name != "Barney");

  cout << endl;
  name = "";
  while (name != "Barney") {
    cout << "What is the name" << endl;
    cin >> name;
  }

  return 0;
}
