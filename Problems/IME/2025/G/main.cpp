#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for(ll i = a; i< b; ++i)
#define per(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back

signed main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ++n;

        vector<double> cs(n);
        for (double& c : cs) cin >> c;

        auto f = [&](double x) {
            double res = 0;
            double p = 1;
            rep(i, 0, n) {
                res += p * cs[i];
                p *= x;
            }
            return res;
        };

        auto binSearch = [&](double l) -> pair<double, bool> {
            double r = l + 0.5;
            if (f(l) * f(r) >= 0)
                return {0.0, false};

            while (r - l > 1e-9) {
                double m = (l + r) / 2.0;
                if (f(l) * f(m) <= 0)
                    r = m;
                else
                    l = m;
            }

            // cout << f(l) << '\n';
            return {l, true};
        };

        double at = -30.0, step = 0.5;
        while (at <= 30.0) {
            auto [root, exists] = binSearch(at);
            if (exists) {
                // cout << "existe\n";
                cout << fixed << setprecision(10) << root << ' ';
            }
            // else cout << "nexiste\n";
            at += step;
        }
        cout << '\n';
    }
}