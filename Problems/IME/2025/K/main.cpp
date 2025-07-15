#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()
signed main() 
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    cin.ignore(1, '\n');
    
    vll a;
    ll ai;
    vll ps(n, 0);
    for(ll i=0; i<n; i++) {
        cin >> ai;
        a.push_back(ai);
    }

    sort(all(a));
    priority_queue<pair<ll, ll>> pq;
    for(ll i=n-1; i>=0; i--) {
        pq.push({a[i]*a[n-1], i});
    }

    ll ans=0;
    for(ll i=0; i<m; i++) {
        pll u = pq.top(); pq.pop();
        ans += u.first;
        ps[u.second]++;

        if(u.second < n)
            pq.push({a[u.second] * a[n - 1 -ps[u.second]], u.second});
    }
    cout << ans << "\n";

    return 0;
}