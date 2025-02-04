#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll l=0, r=0;
    ll swaps=0;

    ll best=1;
    ll ans=0;
    while(r<n) {
        if(s[r]!='a')
            swaps++;

        ans++;
        r++;
        if(swaps<=k) 
            best = max(ans, best);
        
        while(swaps > k && l<r) {
            if(s[l]!='a')
                swaps--;
                
            l++;
            ans--;
        }
    }

    l = 0;
    r = 0;
    swaps=0;
    ans=0;
    while(r<n) {
        if(s[r]!='b')
            swaps++;

        ans++;
        r++;
        if(swaps<=k) 
            best = max(ans, best);
        
        while(swaps > k && l<r) {
            if(s[l]!='b')
                swaps--;
                
            l++;
            ans--;
        }
    }
    
    cout << best << '\n';

    return 0;
}