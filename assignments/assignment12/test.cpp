#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> numbers;
  int x;
  cin >> x;
  while (x !=0)
  {
    numbers.push_back(x);
    cin >> x;
  }

  return 0;
}
