#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define MAXN 10000000

ll distinctPrimeFactors(int N)
{
    if (N < 2) {
        cout << -1;
    }
 
    int c = 2;
    unordered_map<int, bool> visited;
 
    while (N > 1) {
        if (N % c == 0) {
            if (!visited[N]) {
                visited[N] = 1;
            }
            N /= c;
        }
        else
            c++;
    }
    return c;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll ans=0;
        for(ll i=2; i<=n; i++) {
            ll lk = distinctPrimeFactors(i);
            if(lk==2)   
                ans += lk-1;
            else
                ans += lk-2;

        }

        cout << ans << '\n';
    }

    return 0;
}