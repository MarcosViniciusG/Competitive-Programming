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

#define MAXN 200001

signed main() {
    fastio;
    ll N, R, C;
    string S;
    cin >> N >> R >> C >> S;

    map<char, pll> keys;
    keys['N'] = {-1, 0};
    keys['W'] = {0, -1};
    keys['S'] = {1, 0};
    keys['E'] = {0, 1};

    string ans="";
    pll delta[N+1];
    delta[0] = {0,0};
    for(ll i=1; i<=N; i++) {
        bool can=false;
        delta[i].first = delta[i-1].first + keys[S[i]].first;
        delta[i].second = delta[i-1].second + keys[S[i]].second;


        if(!can)
            ans+='0';
        else
            ans+='1';

    }
    cout << ans << '\n';

    return 0;
}