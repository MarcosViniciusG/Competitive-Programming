#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ti, vi;
    cin >> n;

    int result = 0;
    int prev_time;
    for(int i=0; i<n; i++) {
        cin >> ti >> vi;
        if(i==0)
            result = vi;
        else {
            result = max(result - (ti-prev_time), 0);
            result += vi;
        }
        prev_time = ti;
    }

    cout << result << '\n';

    return 0;
}