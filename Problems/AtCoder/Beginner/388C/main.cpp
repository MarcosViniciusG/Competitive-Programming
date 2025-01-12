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
    vll A(N);
    for(ll &i: A)
        cin >> i;

    ll ans=0;
    for(ll i=0; i<N; i++) {
        ll obj = A[i] * 2;
        ans += N - (lower_bound(A.begin(), A.end(), obj) - A.begin());
    }

    cout << ans << '\n';

    return 0;
}