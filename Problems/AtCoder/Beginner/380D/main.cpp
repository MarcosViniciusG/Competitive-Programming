#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll k_th_block) {
  if(k_th_block==0)
    return 0;
  
  return ~solve(k_th_block-1);
}

signed main() {
  string s;
  getline(cin, s);

  ll q, k, n=s.length();
  while(q--) {
    cin >> k;
    ll k_th_block = (k/n);
    ll idx = k%n;


  }

  return 0;
}