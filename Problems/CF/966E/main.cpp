#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll t, n, m, k, w, ai;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;

        cout << n << " " << m << endl;
        cin >> w;
        
        for(ll i=0; i<w; i++)
            cin >> ai;

        cout << m * (m+1) * (3*n - m + 1) / 6 << endl;
    }

    return 0;
}