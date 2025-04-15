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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans(n, '?');
    ll o=0;
    for(ll i=0; i<n; i++) {
        if(s[i]!='?')
            ans[i] = s[i];
        if(s[i]=='o') {
            o++;
            if(i-1>=0)
                ans[i-1]='.';
            
            if(i+1 < n)
                ans[i+1]='.';
        }
    }

    ll point = count(all(ans), '?');
    if(o < k) {
        if(point == (k-o)) {
            for(ll i=0; i<n; i++)
                if(ans[i]=='?')
                    ans[i] = 'o';
        }
        else {
            ll possible=0;
            ll chain=0;
            for(ll i=0; i<n; i++) {
                if(ans[i]=='?') {
                    chain++;
                }

                if(ans[i]!= '?' || i+1==n) {
                    possible += ceil(chain / 2.0);
                    chain=0;
                }
            }

            if(possible == (k-o)) {
                for(ll i=0; i<n; i++)
                    if(ans[i]=='?') {
                        if(i-1 >= 0 && ans[i-1]=='?')
                            continue;
                        if(i+1 < n && ans[i+1]=='?')
                            continue;
                        ans[i] = 'o';
                        possible--;
                    }
                }
            }

            if(possible) {
                ll chains=-1;
                ll chaine=0;
                for(ll i=0; i<n; i++)
                    if(ans[i]=='?') {
                        chains=i;
                        possible--;
                    }
                    else if(chains!=-1) {
                        chains=-1;
                        chaine = i-1;
                        ans[chain]
                        for(ll j=chains; j<=chaine; j++)
                            ans[j] = (ans[])
                    }
                }
            }
    }
    else {
        for(ll i=0; i<n; i++)
                if(ans[i]=='?')
                    ans[i] = '.';
    }

    cout << ans << '\n';

    return 0;
}  