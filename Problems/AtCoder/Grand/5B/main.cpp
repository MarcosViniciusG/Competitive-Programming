#include <bits/stdc++.h>

using namespace std;
using ll =long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

signed main() {
    ll n;
    cin >> n;

    vll a(n);
    // previous smaller element
    vll pse(n);

    // next smaller element
    vll nse(n);

    stack<pll> st;
    for(ll i=0; i<n; i++) {
        cin >> a[i];

        while(!st.empty() && st.top().first >= a[i])
            st.pop();    
            
        if(st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top().second;


        st.push({a[i], i});
    }

    while(!st.empty()) st.pop();
    
    for(ll i=n-1; i>=0; i--) {
        while(!st.empty() && st.top().first >= a[i])
            st.pop();    
            
        if(st.empty())
            nse[i] = n;
        else
            nse[i] = st.top().second;


        st.push({a[i], i});
    }

    ll ans=0;
    for(ll i=0; i<n; i++) {
        ll res = (nse[i]-i)*(i-pse[i])*a[i];
        ans += res;
    }

    cout << ans << '\n';

    return 0;
}