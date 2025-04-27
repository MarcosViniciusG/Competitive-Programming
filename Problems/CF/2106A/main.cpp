#include <bits/stdc++.h>
using namespace std;

using ll =            long long;
#define vll           vector<ll>
#define vvll          vector<vll>
#define pll           pair<ll, ll>
#define vpll          vector<pll>
#define vvpll         vector<vpll>
#define endl '\n'
#define all(xs)       xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll ans=0;
        for(ll i=0; i<n; i++) {
            char temp = s[i];
            if(s[i]=='0')
                s[i] = '1';
            else
                s[i] = '0';

            for(ll j=0; j<n; j++) {
                if(s[j]=='1')
                    ans++;
            }    

            s[i] = temp;
        }   
        
        cout << ans << '\n';
    }


    return 0;
}