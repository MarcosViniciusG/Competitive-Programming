#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Order doesn't matter
// O(a.size())
ll find_n_pairs(vector<ll> a)
{
    ll n=0;
    for(ll i=0; i<a.size(); i++)
        n+=i;
    return n;
}