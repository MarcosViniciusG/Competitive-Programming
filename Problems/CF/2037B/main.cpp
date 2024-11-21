#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, k;
    cin >> t;
    while(t--) {
        cin >> k;
        vector<ll> a(k);

        for(ll i=0; i<k; i++)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        ll matrix_size = k-2;

        ll n, m;
        for(ll i=0; i<k; i++) {
            if(matrix_size % a[i] == 0) {
                ll result = matrix_size/a[i];
                bool have = binary_search(a.begin(), a.end(), result);
                if(have) {
                    n = a[i];
                    m = result;
                    break;
                }
            }
        } 

        cout << n << " " << m << '\n';
    }

    return 0;
}