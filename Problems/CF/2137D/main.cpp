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
    dedinhos;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vll counter(n+1, 0);
        vll arr(n);
        rep(i, 0, n) {
            cin >> arr[i];
            counter[arr[i]]++;
        }

        bool ok = true;

        ll idx=1;
        map<ll, queue<ll>> el;

        rep(i, 1, n+1) {
            if(counter[i] % i != 0) {
                ok = false;
                break;
            }
            else {
                ll ci = counter[i] / i;
                while(ci > 0) {
                    el[i].push(idx);
                    idx++;
                    ci--;
                }
                counter[i] = 0;
            }
        }

        if(!ok) {
            cout << -1 << '\n';
            continue;
        }

        rep(i, 0, n) {
            counter[arr[i]]++;
            cout << el[arr[i]].front() << ' ';
            if(counter[arr[i]] % arr[i] == 0) {
                el[arr[i]].pop();
            }
        }
        cout << '\n';

    }


    return 0;
}