#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<int> coins;
    int ci;
    for(ll i=0; i<n; i++) {
        cin >> ci;
        coins.push_back(ci);
    }

    ll ways[x+1] = {0};
    ways[0]=1;
    for(ll i=1; i<=x; i++) {
        for(ll c: coins) {
            if(i-c >= 0) {
                ways[i] += ways[i-c];
                ways[i] %= ll(1e9 + 7);
            }
        }
    }

    cout << ways[x] << endl;
    return 0;
}