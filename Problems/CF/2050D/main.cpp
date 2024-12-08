#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    string n;

    cin >> t;
    cin.ignore(1, '\n');
    while(t--) {
        getline(cin, n);

        ll start=0;
        for(ll i=0; i<n.length(); i++) {
            for(ll j=1; j<n.length(); j++) {
                if(n[j] - j > (n[i] - 1))
                    start = j;
            }
        }
       
    }

    return 0;
}