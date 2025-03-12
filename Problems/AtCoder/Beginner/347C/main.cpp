#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll , ll >
#define vpll vector <pll >
#define endl '\n'
#define all(xs) xs. begin () , xs.end ()
#define found (x, xs) (xs. find (x) != xs.end ())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    ll t = A+B;

    set<ll> D;
    ll di;
    for(ll i=0; i<N; i++) {
        cin >> di;
        di = di % t;
        D.insert(di);
    }

    vll E;
    for(auto i: D) {
        E.push_back(i);
        cout << i << ' ';
    }
    cout << '\n';

    ll k = E.size();
    bool can=false;
    if(E[k-1] - E[0] < A) {
        can = true;
    }

    for(ll i=0; i<k-1; i++) {
        if(t - (E[i+1] - E[i]) < A)
            can = true;
    }

    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}