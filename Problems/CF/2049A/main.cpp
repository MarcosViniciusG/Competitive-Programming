#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vll a (n);
        for(ll &i: a)
            cin >> i;
        
        bool started=false;
        ll counter=0;
        for(auto e: a) {
            if(e!=0 && !started) {
                started = true;
                counter++;
            }
            else if(e==0 && started) 
                started = false;
        }

        cout << min(2LL, counter) << '\n';
    }

    return 0;
}