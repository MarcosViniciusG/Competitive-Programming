#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, a, b, ci;
    cin >> n >> a >> b;
    ll result = a+b;

    ll correct=0;
    for(int i=0; i<n; i++) {
        cin >> ci;
        if(ci==result)
            correct = i+1;
    }

    cout << correct << "\n";

    return 0;
}