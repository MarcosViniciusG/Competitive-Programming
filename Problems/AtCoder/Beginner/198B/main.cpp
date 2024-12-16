#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
  int n=s.length();
  bool is=true;
  for(int i=0; i < n/2; i++) {
    if(s[i]!=s[s.length() - i - 1]) {
      is=false;
      break;
    }
  }
  
  return is;
}

signed main() {
  string N;
  getline(cin, N);
  int n = N.length();
  
  bool is=is_palindrome(N);
  if(!is) {
    int i;
    for(i=0; i<n && N[i]=='0'; i++);
    
    string ans="";
    for(i=i; i<n; i++) {
      if(N[i]=='0')
        ans += "0";
    }
    
    ans += N;
    is = is_palindrome(ans);
  }
  
  cout << (is ? "Yes": "No") << '\n';
  return 0;
}