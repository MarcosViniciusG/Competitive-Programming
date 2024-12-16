#include <bits/stdc++.h>

using namespace std;

signed main() {
  int N;
  cin >> N;
  cin.ignore(1, '\n');
  
  map<string, long long> mp;
  string s;
  long long counter=0;
  while(N--) {
    getline(cin, s);
    sort(s.begin(), s.end());
    counter += mp[s];
    mp[s]++;
  }
  
  cout << counter << '\n';
  
  return 0;
}