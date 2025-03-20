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

    ll n, a, b;
    cin >> n;

    vector<pair<ll, bool>> times;
    ll ai, bi;
    for(ll i=0; i<n; i++) {
        cin >> ai >> bi;
        times.push_back({ai, true});
        times.push_back({bi, false});
    }

    sort(all(times));

    ll best=1;
    ll customers=0;
    for(ll i=0; i<n*2; i++) {
        if(times[i].second)
            customers++;
        else
            customers--;
        
        best = max(best, customers);
    }

    cout << best << '\n';

    return 0;
}