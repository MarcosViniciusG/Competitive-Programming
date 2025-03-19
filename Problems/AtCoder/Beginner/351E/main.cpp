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

bool reachable(pll p1, pll p2) {
    bool A1 = !(p1.first & 1);
    bool A2 = !(p1.second & 1);

    bool B1 = !(p2.first & 1);
    bool B2 = !(p2.second & 1);

    if(A1==A2 && B1==B2)
        return true;
    else if(A1!=A2 && B1!=B2)
        return true;

    return false;
}

ll dist(ll x1, ll x2) {
    return abs(x1 - x2);
}

signed main() {
    fastio;
    ll N;
    cin >> N;

    vpll points(N);
    for(pll &p: points) {
        cin >> p.first >> p.second;
    }
    ll ans=0;
    for(ll i=0; i<N-1; i++) {
        for(ll j=i+1; j<N; j++) {
            if(reachable(points[i], points[j])) {
                ll mn = min(dist(points[i].first, points[j].first), dist(points[i].second, points[j].second));
                ans += mn + max(dist(points[i].first, points[j].first)-mn, dist(points[i].second, points[j].second)-mn);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}