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

const ll MAXN = ll(1LL << 31); 

ll f(ll d, ll y, ll N)
{
    return (d*d) - N + (3*d*y) + (3*y*y); 
}

signed main() {
    fastio;
    ll N;
    cin >> N;

    ll ans1=-1, ans2=-1;
    ll d=1;
    for(d=d; d*d*d<=N*2; d++) {
        ll l=1;
        ll r=600000001;

        if(N % d != 0)
            continue;

        while(r-l>1) {
            ll m = (l+r)/2;
            if(f(d, m, N/d)>0) 
                r = m;
            else 
                l = m;
        }

        if(f(d, l, N/d)==0) {
            ans1 = l+d;
            ans2 = l;
            break;
        }
    }

    if(ans1==-1 && ans2==-1)
        cout << -1 << '\n';
    else
        cout << ans1 << ' ' << ans2 << '\n'; 

    return 0;
}