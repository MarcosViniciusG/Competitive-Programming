#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N;
    cin >> N;
    vll S(N);
    for(ll &i: S)
        cin >> i;

    ll ans[N] = {0};
    vll ms;
    for(ll i=0; i<N; i++) {
        ll stones_received = ms.end() - lower_bound(ms.begin(), ms.end(), i);
        S[i] += stones_received;
        ll an = S[i] - (N - i - 1);
        ll rest=0;
        ll idx=i;
        if(an >= 0) {
            rest = an;
            idx = N-1;
        }
        else {
            rest = 0;
            idx = (N - abs(an) - 1);
        }
        // cout << S[i] << ' ' << an << ' ' << rest << ' ' << idx << '\n';

        auto it = upper_bound(ms.cbegin(), ms.cend(), idx);
        ms.insert(it, idx);

        ans[i] = rest;
    }

    for(auto e: ans)
        cout << e << ' ';
    cout << '\n';

    return 0;
}