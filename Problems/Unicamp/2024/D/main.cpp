#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    
    ll sm=0;
    ll sqrsm=0;
    ll l=0;
    ll r=k;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(i < r) {
            sm += a[i];
            sqrsm += a[i]*a[i];
        } 
    }

    double ans;
    double m = sm / double(k);
    ll bestl=l, bestr=k;
    for(; r<n; r++) {
        double res = sqrsm - 2*m*sm + k*m*m;
        res /= k;
        // cout << sm << ' ' << m << ' ' << res << '\n';
        res = sqrt(res);

        if(l == 0 || res < ans) {
            ans = res;
            bestl = l;
            bestr = r;
        }

        sm -= a[l];
        sqrsm -= a[l]*a[l];
        l++;
        sm += a[r];
        sqrsm += a[r]*a[r];
        m = sm / double(k);
    }

    double res = sqrsm - 2*m*sm + k*m*m;
    res /= k;
    res = sqrt(res);
    if(l == 0 || res < ans) {
            ans = res;
            bestl = l;
            bestr = r;
        }
    

    cout << bestl+1 << ' ' << bestr << '\n';
    cout << fixed << setprecision(10) <<  ans << '\n';
}