#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    priority_queue<ll> pq;
    ll Q, T, H;

    ll soma=0;
    cin >> Q;
    for(ll i=0; i<Q; i++) {
        cin >> T;
        if(T==1) {
            pq.push(-soma);
        }
        else if(T==2) {
            cin >> H;
            soma += H;
        }
        else if(T==3) {
            cin >> H;
            ll contando=0;
            while(!pq.empty() && (pq.top()+soma >= H)) {
                contando++;
                pq.pop();
            }

            cout << contando << '\n';
        }
    }

    return 0;
}