#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, b, c) for(ll i=i; i<b; i+=c)
#define MAXN 10000010

pair<vll, vector<bool>> sieve(ll n) {
    vll qnt(n+1, 0);
    vector<bool> isPrime (n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i=2; i<=n; i++) {
        if(isPrime[i]) {
            qnt[i]++;
            for(ll j=i+i; j<=n; j+=i)
                isPrime[j] = false;
        }
        qnt[i] += qnt[i-1];
    }
    return {qnt, isPrime};
}

signed main() {
    auto [qnt, isPrime] = sieve(MAXN);
    ll q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        ll j = n;
        while(isPrime[j] && j > 2) {
            j = qnt[j]-1;
        }


        if(!isPrime[j])
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}