#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(1)
void swapNumbers(ll &x, ll &y) {
    x = (x^y);
    y = (x^y);
    x = (x^y);
}