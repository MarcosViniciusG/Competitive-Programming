#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define MAXN 10000000

ll solve(ll n) {
    vll primes;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    ll ans=0;
    for(ll i=2; i<=n; i++) {
        if(isPrime[i]) {
            ans += n/i;
            if(i*i <= n)
                for(ll j=i*i; j<=n; j+=i) 
                    isPrime[j] = false;
        }
    }

    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        ll ans = solve(n);

        cout << ans << '\n';
    }

    return 0;
}