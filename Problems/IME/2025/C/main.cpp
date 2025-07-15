#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back

signed main() {
    ll n;
    cin >> n;
    cin.ignore();
    set<string> ss;
    rep(i, 0, n) {
        string s;
        getline(cin, s);
        ss.emplace(s);
    }

    rep(i, 0, n) {
        string s;
        getline(cin, s);
        ss.erase(s);
    }

    cout << ss.size() << '\n';
    for (auto& t : ss) {
        cout << t << '\n';
    }
}
