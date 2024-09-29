#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
    ll t, n, ai;
    cin >> t;
    while(t--) {
        cin >> n;

        // Minimum is 1
        ll half = ((n/2) + 1);

        vector<ll> a;

        double total = 0;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            total += ai;
            a.push_back(ai);
        }

        if(n <= 2) {
            cout << -1 << endl;
            continue;
        }

        sort(a.begin(), a.end());

        double avg = ((total / n) / 2.0);

        ll c=0;
        for(ll i=0; i<n; i++) {  
            if(a[i] >= avg && i <= (half-1))
                c = a[i];
        }

        ll x = ceil(max((c - avg),0.0) * n * 2.0);

        if(c >= ((x + total) / 2.0 / n))
            x++;

        cout << x << endl;
    }

    return 0;
}