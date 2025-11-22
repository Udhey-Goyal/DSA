// Given a function n, write a function that generates and prints all binary numbers with decimal values
// from 1 to n.
// Input: n = 2
// Output: 1, 10
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n)
{
  queue<string> q;
  q.push("1");

  for (int i = 1; i <= n; i++)
  {
    string s = q.front();
    q.pop();
    cout << s << " ";
    q.push(s + "0");
    q.push(s + "1");
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  generateBinary(n);
  return 0;
}
