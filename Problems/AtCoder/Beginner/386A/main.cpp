#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> st;

    st.insert(a);
    st.insert(b);
    st.insert(c);
    st.insert(d);

    cout << ((int(st.size()) == 2) ? "Yes" : "No") << '\n';

    return 0;
}