#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(log(min(a, b)))
// It's an associative operation, so gcd(a, gcd(b, c)) = gcd(gcd(a, b), c). 
// Thus gcd(a, b, c, ...) can be used for multiple elements
ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
} 