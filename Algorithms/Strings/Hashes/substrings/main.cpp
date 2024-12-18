#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll q = ll(1e9) + ll(7);
ll p = 31;

int to_int(char c) {
    return c - 'a' + 1;
}

ll h(string s) {
    ll ans=0;

    for(auto c: s) {
        ans = (ans * p) % q;
        ans = (ans + to_int(c)) % q;
    }

    return ans;
}

vll prefixes(string s) 
{
    ll n = s.length();
    vll ps(n, 0);

    for(ll i=0; i<n; i++) 
        ps[i] = h(s.substr(0, i+1));

    return ps;
}

ll fast_exp_mod(ll a, ll n) {
    ll res=1, base=a;

    while(n) {
        if(n & 1)
            res = (res*base) % q;
        
        base = (base*base) % q;
        n >>=1;
    } 

    return res;
}

vll inverses(ll n)
{
    vll is(n);
    ll base=1;

    for(ll i=0; i<n; i++) {
        is[i] = fast_exp_mod(base, q-2);
        base = (base*p) % q;
    }
    
    return is;
}

ll h2(ll i, ll j, vll ps, vll is) {
    auto diff = i ? ps[j] - ps[i-1] : ps[j];
    diff = (diff*is[i]) % q;

    return(diff + q) % q;
}

ll unique_substrings(string s) {
    unordered_set<ll> hs;
    ll n = s.length();

    vll ps = prefixes(s);
    vll is = inverses(n);

    for(ll i=0; i<n; i++) {
        for(ll j=i; j<n; j++) {
            ll hij = h2(i, j, ps, is);

            hs.insert(hij);
        }
    }

    return hs.size();
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;

    cout << unique_substrings(s) << '\n';

    return 0;
}