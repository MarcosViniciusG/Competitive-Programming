#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

const ll q = ll(1e9);

signed main() {
    fastio;
    ll n, k;
    cin >> n >> k;

    ll fib[n+1];
    ll presum[n+2];
    memset(presum, 0, sizeof(presum));
    presum[0]=0;
    for(ll i=0; i<k; i++) {
        fib[i] = 1;
        presum[i+1] += presum[i] + fib[i];
    }

    fib[k] = k;
    presum[k+1] = k;  

    for(ll i=k+1; i<=n; i++) {
        fib[i] = (presum[i] - presum[i-k-1]) % q;
        presum[i+1] = presum[i] + fib[i];
    }
    cout << fib[n] % q << '\n';

    return 0;
}