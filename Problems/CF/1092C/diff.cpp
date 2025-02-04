#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    string a, b;
    cin >> a >> b;

    for(ll i=0; i<ll(a.length()) && i<ll(b.length()); i++) {
        if(a[i] != b[i])
            cout << i << '\n';
    }

    return 0;
}