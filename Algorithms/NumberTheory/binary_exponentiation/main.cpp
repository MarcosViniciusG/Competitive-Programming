#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Calculate a^n
// O (log n)
ll binpow(ll a, ll n) {
    if(n==0)
        return 1;
    ll res = binpow(a, n/2);
    // Se for ímpar
    if(n % 2)
        return res * res * a;
    // Se for par
    else
        return res * res;
}