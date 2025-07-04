#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll p(n);
        vll h(n);

        for(ll &i: p)
            cin >> i;
        for(ll &i: h)
            cin >> i;

        ll l=-1, r = 1000000;
        while(r - l > 1) {
            ll m = (l + r) / 2;

            ll maiorq=0;
            ll ig=-1;
            for(ll i=0; i<n; i++) {
                if(p[i] != m && ig==-1)
                    ig = h[i] - p[i];
            

                if(m > p[i])
                    maiorq++;
                
            }

            if(maiorq > 0)
                r = m;
            else
                l = m;
        } 

        ll ans=-1;
        set<ll> st;
        for(ll i=0; i<n; i++) { 
            if(p[i] != l || (h[i] - p[i] < 0))
                st.insert(h[i] - p[i]);
            else
                ans = max(ans, h[i] - p[i]);
        }

        if(st.size()==1) {
            if(ans <= (*st.begin()))
                ans= (*st.begin());
            else
                ans = -1;
        }
        else if(st.size() > 1)  
            ans = -1;


        ans = max(ans, -1LL);
    
        cout << ans << '\n';

    }

    return 0;
}