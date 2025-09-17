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
    ll n, k;
    cin >> n >> k;


    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vll xs(n);
    xs[0] = x;
    cout << x << ' ';
    for(ll i=1; i<n; i++) {
        xs[i] = (a*xs[i-1] + b) % c; 
        cout << xs[i] << ' ';
    }
    cout << '\n';

    ll l=0;
    deque<pair<int, int>> q;
    vll ans;
    for(ll i=0; i<k; i++) {
        while(!q.empty() && q.front().first > xs[i]) {
            q.pop_front();
        }

        q.push_front({xs[i], i});
    }

    ans.push_back(q.back().first);

    for(ll i=k; i<n; i++) {
        while(!q.empty() && (q.front().first > xs[i])) {
            q.pop_front();
        }

        q.push_front({xs[i], i});
        ans.push_back(q.back().first);
    }

    for(ll i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';

    ll num=ans[0];
    for(ll i=1; i<ans.size(); i++)
        num ^= ans[i];

    cout << num << '\n';

    return 0;
}