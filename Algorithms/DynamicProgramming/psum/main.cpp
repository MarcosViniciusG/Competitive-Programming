#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> psum(vector<ll> a) {
    vector<ll> prefixes;
    prefixes.push_back(0);

    for(ll i=0; i<a.size(); i++) {
        prefixes.push_back(prefixes[i] + a[i]);
    }

    return prefixes;
}

// l must start at 1 and r must finish at n (a.size())
ll psumQuery(vector<ll> prefixes, ll l, ll r) {
    return prefixes[r] - prefixes[l-1];
}