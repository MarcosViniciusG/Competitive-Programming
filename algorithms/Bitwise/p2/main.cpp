#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(1)
bool isP2(ll n) {
    return((n !=0) & ((n & (n-1))==0));
}