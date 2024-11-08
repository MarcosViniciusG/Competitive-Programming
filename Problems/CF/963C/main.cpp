#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll t, n, k, ai;
    cin >> t;

    while(t--) {
        cin >> n >> k;
        vll a;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            a.push_back(ai);
        }

        sort(a.begin(), a.end(), greater<ll>());

        ll upper = a[0] + k;
        ll lower = a[0];

        if(a.size()==0) {
            cout << lower << endl;
            continue;
        }

        for(ll i=lower; i>=0; i++) {
            
        }
    }

    return 0;
}