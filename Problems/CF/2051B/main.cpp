#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, a, b, c;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c;
        ll soma = a+b+c;
        ll q = (n/soma);
        ll km_walked = q*soma;
        ll dias = q*3;
        if(km_walked < n) {
            dias++;
            km_walked += a;
        }

        if(km_walked < n) {
            dias++;
            km_walked += b;
        }

        if(km_walked < n) {
            dias++;
            km_walked += c;
        }

        cout << dias << '\n';
    }

    return 0;
}