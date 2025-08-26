#include <bits/stdc++.h>
using namespace std;

#define dedinhos cin.tie(0)->sync_with_stdio(0)
using ll = long long;
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for(ll i = (a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (a); i >= (ll)(b); --i)
#define eb emplace_back

signed main() {
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll counter=0;
        bool ok = false;

        vll ans(n);
        ll k=0;
        priority_queue<pll> pq;
        ll lm=0;
        while(counter < 2*n) {
            counter++;
            ll num;
            if(counter <= n) {
                cout << "? " << counter << " " << n << " ";
                rep(i, 1, n+1) {
                    cout << i;
                    if(i!=n)
                        cout << " ";
                } 
                cout << endl;
                cout.flush();
                cin >> num;
                pq.push({num, counter});
            }
            else {
                ll i=0;
                ll longest=-1;
                while(!pq.empty()) {
                    pll u = pq.top(); pq.pop();
                    if(i==0) {
                        ans[i] = u.second;
                        longest = u.first;
                        lm = longest;
                        i++;
                    }
                    else if(u.first==longest-1) {
                        cout << "? " << ans[i-1] << " " << 2 << " " << ans[i-1] << " " << u.second << endl;
                        cout.flush();
                        cin >> num;
                        
                        // nodes are connected
                        if(num==2) {
                            ans[i] = u.second;
                            longest--;
                            i++;
                        }
                    }
                }
            }

            ok = true;
        }

        if(ok) {
            cout << "! " << lm << " ";
            rep(i, 0, lm) {
                cout << ans[i];
                if(i+1!=lm)
                    cout << ' ';
            }
            cout << endl;
            cout.flush();
        }
        else {
            cout << "! 1 1" << endl;
            cout.flush();
        }
    }

    return 0;
}

// ? 1 4 