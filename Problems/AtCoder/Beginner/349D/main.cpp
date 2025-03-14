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
    ll L, R;
    cin >> L >> R;
    
    vpll ans;
    ll obj=L;
    while(obj!=R) {
        ll nex=obj+1;
        ll l=1;
        for(ll i=0; i <= 61; i++) {
            ll p = (1LL << i);
            if(obj % p == 0) {
                ll div = obj / p;
                ll res = (div+1)*p;
                if((res<=R) && ((res - obj + 1) > l) && (res > nex)) {
                    nex = res;
                    l = (res - obj + 1);
                } 
            }
        }
        ans.push_back({obj, nex});
        obj=nex;
    }

    // ofstream myfile;
    // myfile.open ("out.txt");
    // myfile << ans.size() << '\n';
    // for(auto par: ans)
    //     myfile << par.first << ' ' << par.second << '\n';

    // myfile.close();

    cout << ans.size() << '\n';
    for(auto par: ans)
        cout << par.first << ' ' << par.second << '\n';

    return 0;
}