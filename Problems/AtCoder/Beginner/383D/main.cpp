#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

const ll MX = 4000000;

vll sieve(ll n) {
    const ll S = 10000;

    vll primes;
    ll nsqrt = n;
    vector<char> is_prime(nsqrt + 2, true);
    for (ll i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    return primes;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N;
    cin >> N;

    vll primes = sieve(MX);

    ll ans=0;
    for(ll i=0; primes[i]<=sqrt(N); i++) {
        for(ll j=i+1; primes[j]<=sqrt(N) && primes[i]*primes[j]<=sqrt(N); j++) {
            ans++;
        }
    }

    for(ll i=0; true;i++) {
        ll result=1;
        for(ll k=0; k<8; k++)
            result*=primes[i];

        if(result<=N)
            ans++;
        else
            break;
    }

    cout << ans << '\n';
    return 0;
}