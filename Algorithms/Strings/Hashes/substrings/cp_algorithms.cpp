#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll p = 31;
ll q = ll(1e9) + ll(7);

int to_int(char c) {
    return (c-'a'+1);
}

ll count_unique_substrings(string s) {
    ll n = s.length();

    // Pre-calculate powers of p
    vll p_pow(n);
    p_pow[0] = 1;
    for(ll i=1; i<n; i++) 
        p_pow[i] = (p_pow[i-1] * p) % q;

    // Pre-calculate hashes of prefixes of s
    vll h(n+1, 0);
    for(ll i=0; i<n; i++)
        h[i+1] = (h[i] + to_int(s[i]) * p_pow[i]) % q;
    
    ll cnt=0;
    // Iterate over all substrings of lenght l
    for(ll l=1; l<=n; l++) {
        unordered_set<ll> hs;
        for(ll i=0; i<=n-l; i++) {
            ll cur_h = (h[i+l] + q - h[i]) % q;
            cur_h = (cur_h * p_pow[n-i-1]) % q;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }

    return cnt;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;

    cin >> s;
    cout << count_unique_substrings(s) << '\n';

    return 0;
}