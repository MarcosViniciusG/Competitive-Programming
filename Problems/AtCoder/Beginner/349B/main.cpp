#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin(),xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

map<char, ll> histogram(string s) {
    map<char, ll> hist;
    for(auto c: s) {
        hist[c]++;
    }
    return hist;
}

signed main() {
    fastio;
    string s;
    cin >> s;
    ll n = s.length();
    map<char, ll> hist = histogram(s);
    bool has=true;
    for(ll i=1; i<=100; i++) {
        ll counter=0;
        for(auto par: hist) {
            if(par.second==i) {
                counter++;
            }
        }
        if(counter !=0 && counter !=2)
            has = false;
    }

    cout << (has ? "Yes" : "No") << '\n';
    return 0;
}