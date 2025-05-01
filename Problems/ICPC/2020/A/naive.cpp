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

    vector<double> dp(n+1, 1.0);
    
    double c = double(b+1)/double(b);
    double m = double(1)/double(b-a+1);
    for(ll i=a+1; i<=n; i++) {
        double sum=0;
        for(ll k=a; k<=b; k++) {
            if(i-k <= 0 || k==0)
                sum++;
            else
                sum += 1.0 + dp[i-k];           
        } 
        
        dp[i] = (sum * m); 
        if(!a) dp[i] *= c;
    } 

    cout << fixed << setprecision(5) << dp[n] << '\n';
}