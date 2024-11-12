#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, b, c, t;
    cin >> t;
    while(t--) {
        cin >> n >> b >> c;

        ll no=0;
        if(b==0) {
            if(c>=n)
                no=n;
            else if(n-c > 2)
                no=-1;
            else
                no=n-1;
        }
        else {
            if(c>=n) 
                no = n;
            else 
                no = n-max(0ll, 1+(n-c-1)/b);
        }

        cout << no << '\n';
    }
    

    return 0;
}