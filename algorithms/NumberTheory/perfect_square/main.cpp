#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_psqr(ll n) {
    ll n_sqrt = sqrt(n);
    if((n_sqrt*n_sqrt) == n)
        return true;

    return false;
}
