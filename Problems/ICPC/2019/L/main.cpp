#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll n;

    cin >> n;

    ll ans;
    if(n & 1) 
        ans = 4;
    else
        ans = 2;

    n /= 2;
    while(n > 1) {
        if(n & 1)
            ans *= 2;
        n /= 2;
    }
     
    cout << ans << '\n';
}