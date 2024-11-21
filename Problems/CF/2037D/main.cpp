#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, m, L, li, ri, xi, vi;
    cin >> t;

    while(t--) {
        cin >> n >> m >> L;
        vpll hurdles;

        for(ll i=0; i<n; i++) {
            cin >> li >> ri;
            hurdles.push_back(make_pair(li, ri));
        }

        ll j=0;
        vector<multiset<ll, greater<ll>>> intervals(n);
        for(ll i=0; i<m; i++) {
            cin >> xi >> vi;
            if(j < n) {
                if(xi < hurdles[j].first)
                    intervals[j].insert(vi);
                else {
                    j++;
                    if(j<n)
                        intervals[j].insert(vi);
                }
            }
        }

        ll k = 1;
        ll result = 0;

        for(ll i=0; i<n; i++) {
            if(i>0) {
                intervals[i].insert(intervals[i-1].begin(), intervals[i-1].end());
                intervals[i-1].clear();
            }
            auto it = intervals[i].begin();
            ll length_hurdle = abs(hurdles[i].second - hurdles[i].first) + 1;


            // cout << "LENGTH: " << length_hurdle << '\n';
            while(it != intervals[i].end()) {
                ll el = *(it);      

                if(k <= length_hurdle) {
                    k += el;
                    result++;
                    intervals[i].erase(it++);
                }
                else
                    ++it;
            }

            if(k <= length_hurdle) {
                result = -1;
                break;
            }
        }

        cout << result << '\n';
    }

    return 0;
}