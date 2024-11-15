#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    set<ll> st;
    ll ai;

    ll no=0;
    for(ll i=0; i<4; i++) {
        cin >> ai;
        if(st.find(ai)!=st.end()) {
            st.erase(ai);
            no++;
        }
        else {
            st.insert(ai);
        }
    }

    cout << no << '\n';
    return 0;
}