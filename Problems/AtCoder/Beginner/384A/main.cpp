#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    char c1, c2;
    string S;
    cin >> n >> c1 >> c2;
    cin.ignore(1, '\n');

    getline(cin, S);
    for(int i=0; i<n; i++) {
        if(S[i]!=c1)
            S[i] = c2;
    } 

    cout << S << '\n';

    return 0;
}