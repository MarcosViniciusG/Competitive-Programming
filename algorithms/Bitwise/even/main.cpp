#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Faster than (n % 2 == 0)
// O(1)
bool isEven(ll n) {
    return (n & 1);
}