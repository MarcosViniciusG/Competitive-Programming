#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main() {
    ll n, a, b;

    cin >> n >> a >> b;

    long double dp(n+1, 1);

    long double m = long double(1)/long double(b-a+1);
    for(ll i=a+1; i<=n; i++) {
        dp[i] = 
    }

    cout << dp[n] << '\n';
}