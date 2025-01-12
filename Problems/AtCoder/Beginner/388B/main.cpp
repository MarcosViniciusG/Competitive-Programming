#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, D, Ti, Li;
    cin >> N >> D;
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++) {
        cin >> Ti >> Li;
        v.push_back({Ti, Li});
    }


    for(int i=1; i<=D; i++) {
        int h=0;
        for(int j=0; j<N; j++) {
            v[j].second++;
            h = max(h, v[j].second * v[j].first);
        }
        cout << h << '\n';
    }

    return 0;
}