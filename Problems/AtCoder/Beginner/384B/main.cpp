#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, r;
    int di, ai;
    cin >> n >> r; 
    for(int i=0; i<n; i++) {
        cin >> di >> ai;
        if(di==1) {
            if(r >= 1600 && r <= 2799)
                r = max(r+ai, 0);
        }
        else {
            if(r >= 1200 && r<=2399)
                r = max(r + ai, 0);
        }
    }

    cout << r << '\n';
    return 0;
}