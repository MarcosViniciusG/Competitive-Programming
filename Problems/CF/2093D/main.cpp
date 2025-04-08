#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n, q;
        cin >> n >> q;

        while(q--) {
            string cmd;
            cin >> cmd;
            if(cmd=="->") {
                ll x, y;
                cin >> x >> y;
                cout << "AINDA NAO FOI" << '\n';
            }
            else if(cmd=="<-") {
                ll d;
                cin >> d;

                ll ord = n;
                ll mx = (1 << (2*ord));
                ll offset=1;

                ll il = 0;
                ll ir = 1 << n;
                ll jl = 0;
                ll jr = 1 << n;
                while(ir-il!=0 && jr - jl != 0) {
                    ll imed = (il + ir) / 2;
                    ll jmed = (jl + jr) / 2;

                    if(d <= mx/4) {
                        ir = imed ;
                        jr = jmed;
                        mx = mx/4;
                    }
                    else if(d <= (mx/4)*2) {
                        il = imed;
                        jl  = jmed;
                        mx = (mx/4)*2;
                    }
                    else if(d <= (mx/4)*3) {
                        il = imed;
                        jr = jmed;
                        mx = (mx/4)*3;
                    }
                    else if(d <= mx) {
                        ir =imed;
                        jl = jmed ;
                    }
                }

                cout << il << ' ' << jl << '\n';
            }
        }
    }

    return 0;
}