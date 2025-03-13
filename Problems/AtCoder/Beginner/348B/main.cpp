#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define endl '\n'
#define all(xs) xs.begin() , xs.end()
#define found (x, xs) (xs.find (x) != xs.end())

double dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, xi, yi;
    cin >> n;
    vector<pair<ll, pll>> points;
    for(ll i=0; i<n; i++) {
        cin >> xi >> yi;
        points.push_back({i+1, {xi, yi}});
    }

    for(auto p1: points) {
        ll x1 = p1.second.first;
        ll y1 = p1.second.second;

        ll id;
        double best;
        for(auto p2: points) {
            ll id2 = p2.first;
            ll x2 = p2.second.first;
            ll y2 = p2.second.second;
            if(dist(x1, y1, x2, y2) > best || id2==1) {
                best = dist(x1, y1, x2, y2);
                id = id2;
            }
            else if(dist(x1, y1, x2, y2)==best && id2 < id) {
                id = id2;
            }
        }
        cout << id << '\n';
    }

    return 0;
}