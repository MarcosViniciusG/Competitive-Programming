#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)

/**
 *  @param  s   String.
 *  @return     Vector of pairs (deven, dodd).
 *  deven[i] and dodd[i] represent the biggest palindrome centered at i,
 *  palindrome of size even and odd respectively, even palindromes centered
 *  at i means that it's centered at both i - 1 and i, because they are equal.
 *  Time complexity: O(N)
*/
vpll manacher(string s) {
    string t;
    for(char c : s) t += string("#") + c;
    t += '#';
    ll n = t.size(), l = 0, r = 1;
    t = "$" + t + "^";
    vll p(n + 2);  // qnt of palindromes centered in i.
    rep(i, 1, n + 1) {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while(t[i - p[i]] == t[i + p[i]]) p[i]++;
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    ll m = s.size(), i = 0;
    vpll res(m);
    for (auto& [deven, dodd] : res)
        deven = p[2 * i + 1] - 1, dodd = p[2 * i + 2] - 1, ++i;
    return res;
}

signed main() {
    ll n, m;
    cin >> n >> m;
    vector<string> ss(n);
    for (auto& s : ss) cin >> s;
    vll subpals(n);
    rep(i, 0, n) {
        auto [deven, dodd] = 
    }
}