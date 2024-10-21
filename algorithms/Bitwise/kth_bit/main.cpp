#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// All O(1)

bool isKthBitSet(ll n, int k) {
    return(n & (1 << k));
}

ll toggleKthBit(ll n, int k) {
    return (n ^ (1 << k));
}

ll setKthBit(ll n, int k) {
    return (n | (1 << k));
}

ll unsetKthBit(ll n, int k) {
    return (n & (~(1<<k)));
}