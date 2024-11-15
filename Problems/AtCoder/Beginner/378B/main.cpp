#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, Q;
    cin >> N;

    ll r[N];
    ll q[N];
    for(int i=0; i<N; i++) {
        cin >> q[i] >> r[i];
    }   

    cin >> Q;

    ll ti, di;
    for(int i=0; i<Q; i++) {
        cin >> ti >> di;
        ti--;

        ll day = (di / q[ti])*q[ti]+r[ti];
        if(di > day) {
            day+=q[ti];
        }

        cout << day << '\n';
    }


    return 0;
}