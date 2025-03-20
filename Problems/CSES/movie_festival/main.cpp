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

    vpll movies;
    for(ll i=0; i<n; i++) {
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end());
    ll ans=1;
    ll e = movies[0].second;
    ll watched=1;
    for(ll i=1; i<n; i++) {
        //cout << movies[i].first << ' ' << movies[i].second << '\n';
        if(movies[i].first >= e) {
            e = movies[i].second;
            watched++;
        }

        ans = max(ans, watched);
    }

    cout << ans << '\n';
    return 0;
}