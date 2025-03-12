#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll , ll >
#define vpll vector <pll>
#define endl '\n'
#define all(xs) xs. begin () , xs.end ()
#define found (x, xs) (xs. find (x) != xs.end ())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string S;
    getline(cin, S);

    set<string> st;
    for(ll i=0; i<ll(S.size()); i++) {
        for(ll j=1; j<=ll(S.size()); j++)
            st.insert(S.substr(i, j));
    }

    cout << st.size() << '\n';

    return 0;
}