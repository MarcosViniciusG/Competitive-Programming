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
        if(n==1) {
            if(c!=0)
                no=1;
        }
        else if(b==0) {
            if(n-c > 2)
                no=-1;
            else
                no=n-1;
        }
        else {
            no = n - ceil(double(n)/b);

            if(c+(b*(n-1))>=n)
                no += min(n, abs(c-n));
        }

        cout << no << '\n';
    }
    

    return 0;
}