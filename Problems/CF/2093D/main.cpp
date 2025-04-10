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

                ll ord=n;
                ll ans=1;
                ll hfx = (1LL << (n-1));
                ll hfy = (1LL << (n-1));                
                while(ord>0) {
                    ll v = (1LL << (2*ord - 2));
                    ord--;
                    if(x > hfx) {
                        hfx += (1LL << (ord - 1));
                        if(y > hfy) {
                            ans += v;
                            hfy += (1LL << (ord - 1)); 
                        }
                        else { 
                            ans += v*2;
                            hfy -= (1LL << (ord -1));
                        }
                    }
                    else {
                        hfx -= (1LL << (ord -1));
                        if(y > hfy) {
                            hfy += (1LL << (ord-1));
                            ans += v*3;
                        }
                        else 
                            hfy -= (1LL << (ord-1));
                    }
                }
                
                cout << ans << "\n";
            } 
            else {
                ll d;
                cin >> d;
                ll x=1, y=1;

                ll ord=n;
                while(ord > 0) {
                    ll v =(1LL << (2*ord - 2));
                    if(d <= v) {

                    }
                    else if(d <= v*2) {
                        d -= v;
                        x += (1LL << (ord-1));
                        y += (1LL << (ord-1));
                    }
                    else if(d <= v*3) {
                        d -= v*2;
                        y += (1LL << (ord-1));
                    }
                    else if(d <= v*4) {
                        d -= v*3;
                        x += (1LL << (ord-1));
                    }
                    ord--;
                }
                cout << y << ' ' << x << '\n';
            }         
        }
    }

    return 0;
}