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

bool valid(const string s) {
    ll n= s.size();
    if(n & 1)
        return false;

    for(ll i=0; i<n; i++) {
        if(s[i]=='i' && (i & 1))
            return false;

        if(s[i]=='o' && (i % 2 == 0))
            return false;
    }

    return true;
}

signed main() {
    fastio;
    string s;

    cin >> s;
    map<char, char> mp;
    mp['o'] = 'i';
    mp['i'] = 'o';

    ll ans=0;
    while(!valid(s)) {
        ll n = s.size();

        for(ll i=0; i<n; i++) {
            bool mov = false;
            if(s[i]=='i' && (i & 1)) {
                s.insert(s.begin()+i, mp[s[i]]);
                mov = true;
            }
            else if(s[i]=='o' && (i % 2 == 0)) {
                s.insert(s.begin()+i, mp[s[i]]);
                mov = true;
            }
            
            if(mov) {
                ans++;
                i = -1;
                n = s.size();
            }
        }

        n = s.size();
        if(n & 1) {
            ans++;
            s += 'o';
        }
    }

    cout << ans << '\n';

    return 0;
}