// Write a program to find first non-repeating character in a string using Queue.
// Sample I/P: a a b c Sample O/P: a -1 b b
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
using namespace std;

int main()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  int freq[26] = {0};
  queue<char> q;

  for (char c : s)
  {
    freq[c - 'a']++;
    q.push(c);

    while (!q.empty() && freq[q.front() - 'a'] > 1)
    {
      q.pop();
    }

    if (q.empty())
      cout << -1 << " ";
    else
      cout << q.front() << " ";
  }
  cout << endl;
  return 0;
}