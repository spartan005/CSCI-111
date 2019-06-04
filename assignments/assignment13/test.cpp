#include<iostream>
#include<vector>
using namespace std;

int main()
{
  vector<int> num;
  for (int i = 5; i > -5; i--) {
    cout << i << endl;
    num.push_back(i);
  }


  return 0;
}
