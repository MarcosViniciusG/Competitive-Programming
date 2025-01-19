#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

double dist(double i, double j) {
    return sqrt(pow(i, 2) + pow(j, 2));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll ans=0;    
    double R;
    cin >> R;

    double j = R-1;
    for(double i=1; i<R; i++) {
        double f1 = dist(i+0.5, j+0.5);
        double f2 = dist(i+0.5, j-0.5);
        double f3 = dist(i-0.5, j+0.5);
        double f4 = dist(i-0.5, j-0.5);
        while(f1 > R || f2 > R || f3 > R || f4 > R) {
            j--;
            f1 = dist(i+0.5, j+0.5);
            f2 = dist(i+0.5, j-0.5);
            f3 = dist(i-0.5, j+0.5);
            f4 = dist(i-0.5, j-0.5);
        }
        ans += ll(j) + 1;
    }

    cout << (ans * 4) + 1 << '\n';
    return 0;
}