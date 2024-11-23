#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w;
    char ai, bi;

    cin >> h >> w;

    ll counta=0;
    ll countb=0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> ai;
            if(ai=='#')
                counta++;
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> bi;
            if(bi=='#')
                countb++;
        }
    }

    if(counta==countb)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}