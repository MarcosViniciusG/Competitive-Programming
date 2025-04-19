#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

ll qnt(vll& xs) {
    ll n = xs.size();
    ll qnt_impar = 0, qnt_par = 1;
    ll ans = 0, psum = 0;
    for (ll i = 0; i < n; ++i) {
        psum += xs[i];
        if (psum & 1)
            qnt_impar++;
        else
            qnt_par++;
        if (psum % 2 == 0)
            ans += qnt_impar;
        else
            ans += qnt_par;
    }
    return ans;
}

signed main() {
    ll n;
    cin >> n;
    vll xs(n);
    for (ll& x : xs)
        cin >> x;
    cout << qnt(xs)<< '\n';
}