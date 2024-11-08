#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t, n, k, bi, ci;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> brands(k, 0); // Total gain of each brand
        for(int i=0; i<k; i++) {
            cin >> bi >> ci;
            brands[bi-1] += ci;
        }

        sort(brands.begin(), brands.end(), greater<int>());
        ll soma=0;
        for(int i=0; i<n && i<k; i++) {
            soma += brands[i]; 
        }
        cout << soma << '\n';
    }

    return 0;
}