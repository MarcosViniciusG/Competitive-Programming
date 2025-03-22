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
    ll A[7];
    for(ll i=0; i<7; i++)
        cin >> A[i];
    
    bool can=false;
    for(ll bit=0; bit<(1 << 7); bit++) {
        ll counter=0;
        map<ll, ll> mp;
        for(ll i=0; i<7; i++) {
            if(bit & (1<<i)) {
                counter++;
                mp[A[i]]++;
            }
        }

        bool c1=false;
        bool c2=false;
        if(counter==5) {
            for(auto par:mp) {
                if(par.second==2)
                    c2=true;
                else if(par.second==3)
                    c1 = true;
            }
        }

        if(c1 && c2)
            can = true;
    }

    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}