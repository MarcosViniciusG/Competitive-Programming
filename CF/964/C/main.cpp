#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll t, n, s, m, li, ri;
    cin >> t;

    while(t--) {
        cin >> n >> s >> m;
        bool can = false;
        ll previous_ri=0;
        for(ll i=0; i<n; i++) {
            cin >> li >> ri;
            if(li - previous_ri >= s)
                can = true;
            previous_ri = ri;
        }

        if(m - previous_ri >= s)
            can = true;

        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}