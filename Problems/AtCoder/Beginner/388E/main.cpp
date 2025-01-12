#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    ll N, Ai;
    cin >> N;
    vll A;
    for(ll i=0; i<N; i++) {
        cin >> Ai;
        A.push_back(Ai);
    }

    ll a=1, b=N;
    ll best=0;

    while(b - a > 1) {
        bool bl = true;
        ll ans= (b-a) / 2;
        cout << a << ' ' << b << ' ' << ans << '\n';
        for(ll i=0; i<ans; i++) {
            if(A[i]*2 > A[N-ans+i])
                bl = false;
        }

        if(bl) {
            best = max(best, ans);
            a = ans;
        }
        else {
            b = ans;
        }
    }

    cout << best << '\n';
    return 0;
}