#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

ll llpow(ll a, ll t) {
    ll res = 1;
    for (ll i = 0; i < t; i++) res *= a;
    return res;
}

ll counting(ll x)
{
    vll digit;
    while(x) {
        digit.push_back(x % 10);
        x /= 10;
    }

    reverse(digit.begin(), digit.end());
    ll n = digit.size();
    ll res=0;
    for(ll i=1; i<=n; i++) {
        if(i==n) {
            res++;
            break;
        }

        res += llpow(digit[0], n-1-i) * min(digit[0], digit[i]);
        if(digit[i] >= digit[0]) break;
    }

    for(ll i=0; i<n; i++) {
        ll limit = (i ? 9: digit[0] - 1);
        for(ll j=1; j<=limit; j++) {
            res += llpow(j, n-1-i);
        }
    }

    return res;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    ll L, R;
    cin >> L >> R;

    ll resultR = counting(R);
    ll resultL = counting(L-1);

    cout << resultR - resultL << '\n';
    return 0;
}