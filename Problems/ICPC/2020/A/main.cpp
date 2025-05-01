#include <bits/stdc++.h>
using namespace std;

using ld = long double;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main() {
    ll n, a, b;

    cin >> n >> a >> b;

    if(a >= n) {
        cout << 1 << '\n';
        return 0;
    }

    vector<ld> presum(n+1, 0);
    vector<ld> dp(n+1, 1.0);

    for(ll i=1; i<=a; i++)
        presum[i] = presum[i-1]+1;
    
    ld c = ld(b+1)/ld(b);
    ld m = ld(1)/ld(b-a+1);
    for(ll i=a+1; i<=n; i++) {
        ll l = max(0LL, i-b-1);
        ll r = a ? i-a: i-1;

        dp[i] = (presum[r]-presum[l])*m + 1; 
        if(!a) dp[i] *= c;
        presum[i] = presum[i-1] + dp[i];
    } 

    cout << fixed << setprecision(5) << dp[n] << '\n';
}