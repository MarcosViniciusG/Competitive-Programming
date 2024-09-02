#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O (nlogn)
vector<ll> get_multiples(ll n, ll lim) {
    vector<ll> multiples;
    for (ll i = n; i<lim; i+=n) {
        multiples.push_back(i);
    }
    
    return multiples;
}