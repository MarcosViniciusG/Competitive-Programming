#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll t, n, hi;

    cin >> t;

    while(t--) {
        cin >> n;

        vector<ll> h;
        ll timee = 0;


        for(int i=0; i<n; i++) {
            cin >> hi;
            h.push_back(hi);
        }

        ll t1=h[n-1];

        for(int i=n-2; i>=0; i--) {
            t1 = max(t1 + 1, h[i]);
        }

        cout << t1 << endl;
    }

    return 0;
}