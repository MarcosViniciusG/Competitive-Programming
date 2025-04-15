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

    int n;
    cin >> n;
    bool logged=false;
    ll ans=0;
    while(n--) {
        string s;
        cin >> s;
        if(!logged && s=="private")
            ans++;

        if(s=="login")
            logged = true;
        else if(s=="logout")
            logged = false;
    }


    cout << ans << "\n";
    return 0;
}