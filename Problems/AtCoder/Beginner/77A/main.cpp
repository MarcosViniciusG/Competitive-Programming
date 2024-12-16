#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string a, b;
  getline(cin, a);
  getline(cin, b);
  reverse(b.begin(), b.end());
  if(b==a)
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
  return 0;
}