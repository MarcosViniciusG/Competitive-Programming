#include <bits/stdc++.h>
using namespace std;

using ll =            long long;
#define vll           vector<ll>
#define vvll          vector<vll>
#define pll           pair<ll, ll>
#define vpll          vector<pll>
#define vvpll         vector<vpll>
#define endl '\n'
#define all(xs)       xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n, x;
        cin >> n >> x;

        vll ans;
        for(ll i=0; i<n; i++) {
            if(i==x)
                continue;
            
            ans.push_back(i);
        }

        if(x < n)
            ans.push_back(x);

        for(auto e: ans)
            cout << e << ' ';
        cout << '\n';
    }


    return 0;
}