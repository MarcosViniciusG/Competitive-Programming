#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n, k;
    cin >> n >> k;

    vll a1;
    vll a2;

    ll ai;
    for(ll i=0; i<n; i++) {
        cin >> ai;
        if(i >= n/2)
            a2.push_back(ai);
        else
            a1.push_back(ai);
    }

    ll a, b;
    cin >> a >> b;

    unordered_map<ll, vll> mp1, mp2;
    for(ll bit=0; bit<(1 << a1.size()); bit++) {
        ll c=0;
        ll soma=0;
        for(ll i=0; i<n; i++) {
            if(bit & (1 << i)) {
                c++;
                soma += a1[i];
            }
        }

        if(c <= k)
            mp1[c].push_back(soma);
    }

    for(ll bit=0; bit<(1 << a2.size()); bit++) {

        ll c=0;
        ll soma=0;
        for(ll i=0; i<n; i++) {
            if(bit & (1 << i)) {
                c++;
                soma += a2[i];
            }
        }

        if(c<= k)
            mp2[c].push_back(soma);
    }

    for(ll i=0; i<=k; i++) {
        sort(all(mp1[i]));
        sort(all(mp2[i]));
    }

    ll ans=0;
    for(ll i=0; i<=k; i++) {
        for(auto e: mp1[i]) {
            ll lb = a - e;
            ll ub = b - e;

            // cout << i << ": " << e << ' ' << lb << ' ' << ub << '\n';

            if(ub < 0)
                continue;

            auto lbit = lower_bound(all(mp2[k-i]), lb);
            auto ubit = upper_bound(all(mp2[k-i]), ub);

            ll lidx = lbit - mp2[k-i].begin();
            ll uidx = ubit - mp2[k-i].begin();

            ans += uidx - lidx;
        }
    }

    cout << ans << '\n';
}