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

bool comp(pll x, pll y) {
    if(x.first + y.second > x.second + y.first)
        return true;

    return false;
}

signed main() {
    fastio;
    ll N;
    cin >> N;

    vpll giants(N);
    for(ll i=0; i<N; i++)
        cin >> giants[i].first >> giants[i].second;

    sort(giants.begin(), giants.end(), comp);

    ll ans=0;
    for(ll i=0; i<N; i++) {
        if(i==N-1)
            ans += giants[i].second;
        else
            ans += giants[i].first; 
    }

    cout << ans << '\n';

    return 0;
}