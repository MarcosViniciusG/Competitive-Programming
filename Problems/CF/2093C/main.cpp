#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

bool isPrime(ll n) {
    for(ll d=2; d*d <= n; d++)
        if(n%d==0)
            return false;
    
    return n >= 2;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll t;
    cin >> t;
    while(t--) {
        ll x, k;
        cin >> x >> k;
        if(isPrime(x) && k==1 || (x==1 && k==2))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}