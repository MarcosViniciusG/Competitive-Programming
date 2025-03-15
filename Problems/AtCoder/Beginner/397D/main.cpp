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

const ll MAXN = ll(1LL << 62); 

ll cubed(ll x) {
    return x*x*x;
}

signed main() {
    fastio;
    ll N;
    cin >> N;

    map<ll, ll> root;
    for(ll x=1; N-cubed(x)>=-MAXN; x++) {
        root[N-cubed(x)] = x;
    }

    ll ans1=-1, ans2=-1;
    for(ll y=1; cubed(y)<=MAXN; y++) {
        if(found(-cubed(y), root)) {
            ans1 = root[-cubed(y)];
            ans2 = y;
            break;
        }
    }

    if(ans1==-1 && ans2==-1)
        cout << -1 << '\n';
    else
        cout << ans1 << ' ' << ans2 << '\n'; 

    return 0;
}