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
    map<ll, vll> mp;
    set<pll> st;

    ll n;
    cin >> n;
    ll a[n];

    for(ll i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    for(auto par: mp) {
        if((ll)par.second.size()==1)
            st.insert({par.first, par.second[0]});
    }

    if(!st.empty()) {
        auto it = st.end();
        it--;

        cout << (*it).second+1 << '\n'; 
    }
    else
        cout << -1 << '\n';



    return 0;
}