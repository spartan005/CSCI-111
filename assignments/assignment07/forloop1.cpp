#include<iostream>
using namespace std;

int main()
{
  int hi;

  cout << "How many times they want the computer to print Hi?" << endl;
  cin >> hi;
  for (hi > 0; hi--;) {
    cout << "Hi" << endl;
  }
  return 0;
}
