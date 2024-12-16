#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fact(ll n) {
    ll ans=1;
    for(ll i=1; i<=n; i++)
        ans *= i;

    return ans;
}

string build(int n) {
    string ans="";
    for(int k=0; k<=n; k++) {
        ans += to_string((fact(n) / (fact(k) * fact(n-k))) % 2); 
    }

    return ans;
}

signed main() {
    int n;
    cin >> n;

    cout << build(n) << '\n';

    return 0;
}