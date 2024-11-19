#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char flip(char c){
  if('a'<=c && c<='z'){
    return (c-'a')+'A';
  }
  else{
    return (c-'A')+'a';
  }
}

bool solve(ll k_th_block) {
  if(k_th_block==0)
    return false;
  
  ll msb = 0;
  ll n = k_th_block / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }

  bool result = solve(k_th_block - (ll(1) << msb));
  if(result)
    return false;
  else
    return true;
}

signed main() {
  string s;
  getline(cin, s);

  ll q, k, n=s.length();
  cin >> q;
  while(q--) {
    cin >> k;
    k--;
    ll k_th_block = (k/n);
    char c = s[k%n];
    bool cas = solve(k_th_block);
    if(cas)
      cout << flip(c) << ' ';
    else
      cout << c << ' ';
    
  }
  cout << '\n';

  return 0;
}