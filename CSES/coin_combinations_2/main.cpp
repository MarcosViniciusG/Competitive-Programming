#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> coins;
ll n, x;

int main() {
    ll ci;
    cin >> n >> x;

    for(ll i=0; i<n; i++) {
        cin >> ci;
        coins.push_back(ci);
    }
    
    ll ways[x+1] = {0};
    ways[0] = 1;

    // We only go through each coin once
    for(auto coin: coins) {
        for(ll j=1; j<=x; j++) {
            if(j - coin >= 0) {
                ways[j] += ways[j-coin];
                ways[j] %= ll(1e9 + 7);
            }
        }
    }

    cout << ways[x] << '\n';

    return 0;
}