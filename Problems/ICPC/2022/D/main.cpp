#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, b, a) for (ll i = (b); i >= (a); --i)
#define x first
#define y second

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, xi, yi;
    cin >> N >> xi >> yi;

    ll px = (1 << (N -1)), py= (1 << (N-1));
    ll movimentos=0;
    while(px != xi || py != yi) {
        if(px > xi) 
            px /= 2;
        else 
            px = ((1 << N) - px) / 2;

        if(py > yi) 
            py /= 2;
        else
            py = ((1 << N) - py)/2;

        movimentos++;
        cout << px << " " << py << '\n';
    }

    cout << movimentos << '\n';
    return 0;
}