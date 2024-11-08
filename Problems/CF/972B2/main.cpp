#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<ll, ll> bin_search(vector<ll> a, ll k) {
    ll l = -1, r = a.size();
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (k < a[m]) {
            r = m; // a[l] <= k < a[m] <= a[r]
        } else {
            l = m; // a[l] <= a[m] <= k < a[r]
        }
    }
    return make_pair(l, r);
}

int main() {
    int t;
    ll n, m, q, bi, ai;
    cin >> t;
    while(t--) {
        cin >> n >> m >> q;
        
        vector<ll> b;

        for(ll i=0; i<m; i++) {
            cin >> bi;
            b.push_back(bi);
        }

        sort(b.begin(), b.end());

        while (q--)
        {   
            cin >> ai;

            pair<ll, ll> result = bin_search(b, ai);

            ll dist;
            if(result.first==-1)  
                dist = b[0] - 1;
            else if(result.second == m) { 
                dist = n - b[m-1];
            }
            else {
                ll le = b[result.first];
                ll ri = b[result.second];

                if(abs(ai - le) >= abs(ai-ri)) {
                    ll stu = le + 1;
                } 
            }

            cout << max(dist, ll(1)) << endl;
        }
    }

    return 0;
}