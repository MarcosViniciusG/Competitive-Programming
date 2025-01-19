#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        multiset<ll> st;

        ll ai;
        queue<ll> a;
        queue<ll> b;
        queue<pll> pares;
        ll score=0;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            auto itr = st.find(k-ai);
            if(itr!=st.end()) {
                score++;
                st.erase(itr);
            }
            else 
                st.insert(ai);
        }
        
        cout << score << '\n';
    }

    return 0;
}