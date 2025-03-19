#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

signed main() {
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    
    vll a(n);
    for(ll &i: a)
        cin >> i;

    sort(all(a));
    vll b(m);
    for(ll &i: b)
        cin >> i;

    sort(all(b));

    ll ans=0;
    ll j=0;
    for(ll i=0; i<n && j<m; i++, j++) {
        bool found=true;
        ll dist=a[i]-b[j];
        while(abs(dist)>k && i<n && j<m) {
            // If the apartment is larger
            // than what the least customer wants
            // go to the next 
            if(dist > 0) 
                j++;
            else 
                i++;
            dist=a[i]-b[j];
        }

        if(abs(dist)<=k) {
            ans++;
        }
    }

    cout << ans << '\n';


    return 0;
}