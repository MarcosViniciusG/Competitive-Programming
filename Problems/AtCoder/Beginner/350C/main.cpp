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
    ll N;
    cin >> N;
    vll A(N);
    map<ll, ll> mp1; // Key: IDX, Value: El
    map<ll, ll> mp2; // Key: El, Value: IDX
    for(ll i=0; i<N; i++) {
        cin >> A[i];
        mp1[i] = A[i];
        mp2[A[i]] = i;
    }

    vpll ans;
    for(ll i=0; i<N; i++) {
        ll el = i+1;
        ll idx = mp2[el];

        if(el != idx+1) {
            ll obj = mp1[el-1]; // Who is at pos of the el
            mp2[el] = el-1;
            mp2[obj] = idx;
            
            mp1[el-1] = el;
            mp1[idx] = obj; 

            pll par;
            if(idx+1 > el)
                ans.push_back({el, idx+1});
            else
                ans.push_back({idx+1, el});
        }
    }

    cout << ans.size() << '\n';
    for(auto par: ans)
        cout << par.first << ' ' << par.second << '\n';

    return 0;
}