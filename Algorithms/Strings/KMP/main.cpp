#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

vll strong_borders(string s) {
    ll m = s.length(), t=-1;
    vll bs(m+1, -1);

    for(ll i=1; i<=m; i++) {
        while(t>-1 && s[t] != s[i-1])
            t = bs[t];

        t++;
        bs[i] = (i==m || s[t] != s[i]) ? t: bs[t];
    }

    return bs;
}

ll KMP(string s, string p) {
    ll n = s.length(), m=p.length(), i=0, j=0, occ=0;

    vll bs = strong_borders(p);

    while(i<=n - m) {
        while(j < m && p[j]==s[i+j])
            j++;
        
        if(j==m) occ++;

        ll shift = j-bs[j];
        i += shift;
        j = max(0LL, j-shift);
    }

    return occ;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    
    cout << KMP(s, p) << '\n';

    return 0;
}