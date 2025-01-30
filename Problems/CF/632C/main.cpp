#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

bool cmp(string a, string b) {
    return (a+b) < (b+a);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;

    vector<string> v;
    string s;
    cin.ignore(1, '\n');
    for(ll i=0; i<n; i++) {
        getline(cin, s);
        v.push_back(s);
    }   

    sort(v.begin(), v.end(), cmp);
    for(auto e: v)
        cout << e;

    cout << '\n';

    return 0;
}