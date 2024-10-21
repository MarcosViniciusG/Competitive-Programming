#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 1000010;
ll n_divs[MAXN] = {0};

// O(nsqrt(n)) is too slow

// O(nlogn)
void solve() {
    for(ll i=1; i<MAXN; i++) {
        // Multiples of i
        // i is divisor of j
        for(ll j=i; j<MAXN; j+=i) {
            n_divs[j]++;
        }
    }
}

int main() {
    ll n, x;
    cin >> n;

    solve();

    while (n--)
    {
        cin >> x;
        cout << n_divs[x] << endl;
    }
    

    return 0;
}