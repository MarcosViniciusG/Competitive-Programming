#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

const ll MAXN = ll(2*ll(1e5) + 1);

vector<bool> sieveOfEratosthenes(ll n)
{
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n;

    vector<bool> prime = sieveOfEratosthenes(MAXN);
    cin >> t;

    while (t--)
    {
        cin >> n;

    }
    
    return 0;
}