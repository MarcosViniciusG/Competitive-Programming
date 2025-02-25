#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

const ll INF = ll(1E18)+16;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, m, ai, bi;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        vll a(n), b(m);

        for(ll &i: a)
            cin >> i;
        
        for(ll &i: b)
            cin >> i;

        sort(b.begin(), b.end());

        a[0] = min(a[0], b[0] - a[0]);
        bool can = true;
        for(ll i=1; i<n; i++) {
            ll l=-1;
            ll r=m;
            ll mid = (l + r)/2;
            while(r - l > 1) {
                mid = (l + r)/2;
                if(b[mid] - a[i] >= a[i-1])
                    r = mid;
                else
                    l = mid;
            }

            mid = (l+r)/2;

            // v is the minimum value so that v-a[i] >= a[i-1]
            ll v;
            if(r!=m)
                v = b[r];
            else
                continue;
            
            // Maintaining the value of a[i] can't give the right ans
            // if a[i] < a[i-1]
            ll va = (a[i] < a[i-1]) ? INF : a[i];

            //  Switching the value a[i] can't give the right ans
            // if v-a[i] < a[i-1]  
            ll vb = (v-a[i] < a[i-1]) ? INF: v-a[i];

            // a[i] can not be changed so that a[i] >= a[i-1]
            if(va==INF && vb==INF) continue;
            
            // a[i] is the minimum value between a[i] and v-a[i]
            a[i] = min(va, vb);
        }

        // is_sorted is for non-descending order
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
    }

    return 0;
}