#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    set<string> st;

    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll n = s.size();

    for(ll i=0; i<n; i++) {
        for(ll j=1; j<=n; j++) {
            st.insert(s.substr(i, j));
        }
    }

    ll counter=1;
    auto it = st.begin();
    while(counter < k) {
        counter++;
        it++;
    }

    cout << *it << '\n';

    return 0;
}