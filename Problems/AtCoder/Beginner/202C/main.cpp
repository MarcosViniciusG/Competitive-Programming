#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  cin >> N;
  vi A(N);
  vi B(N);
  vi C(N);
  
  for(int &i: A)
    cin >> i;
    
  for(int &i: B)
    cin >> i;
    
  for(int &i: C)
    cin >> i;
    
  vi hist(N+1, 0);
  for(auto e: C)
    hist[B[e-1]]++;
    
  long long counter=0;
  for(auto e: A)
    counter+= hist[e];
    
  cout << counter << '\n';
  
  return 0;
}