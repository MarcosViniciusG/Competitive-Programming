#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define pll pair<ll, ll>
#define vpll vector<pll>
#define x first
#define y second

template <typename T>
T D(const pair<T, T>& A, const pair<T, T>& B, const pair<T, T>& P) {
    return (A.x * B.y + A.y * P.x + B.x * P.y) -(P.x * B.y + P.y * A.x + B.x * A.y);
}

template <typename T>
vector<pair<T, T>> makeHull(const vector<pair<T, T>>& PS) {
    vector<pair<T, T>> hull;
    for (auto& P : PS) {
        ll sz = hull.size();
        while (sz >= 2 and D(hull[sz - 2], hull[sz - 1], P) < 0) {
            hull.pop_back();
            sz = hull.size();
        }
        hull.emplace_back(P);
    }
    return hull;
}

template <typename T>
vector<pair<T, T>> monotoneChain(vector<pair<T, T>> PS) {
    vector<pair<T, T>> lower, upper;
    sort(all(PS));
    lower = makeHull(PS);
    reverse(all(PS));
    upper = makeHull(PS);
    lower.pop_back();
    lower.insert(lower.end(), all(upper));
    return lower;
}

signed main() {
    ll n;
    cin >> n;
    vpll ps(n);
    map<pll, ll> mp;
    for (ll i = 0; i < n; ++i) {
        cin >> ps[i].first >> ps[i].second;
        mp.emplace(ps[i], i + 1);
    }
    sort(all(ps));
    bool ok = true;
    for (ll i = 0; i < n; ++i)
        if (D(ps[0], ps[1], ps[i]) != 0)
            ok = false;
    if (ok) {
        for (ll i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return 0;
    }
    auto aaa = monotoneChain(ps);
    aaa.pop_back();
    // for (auto [x, y] : aaa)
    //     cout << x << ' ' << y << '\n';
    vll xs(aaa.size());
    for (ll i = 0; i < aaa.size(); ++i)
        xs[i] = mp[aaa[i]];
    sort(all(xs));
    for (ll i = 0; i < xs.size(); ++i)
        cout << xs[i] << ' ';
    cout << '\n';
}