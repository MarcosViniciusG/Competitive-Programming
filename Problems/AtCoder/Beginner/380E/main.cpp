#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, Q, t, x, c;
vector<ll> C;
vector<ll> D;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> Q;


    for(ll i=0; i<N; i++) {
        C.push_back(1);
        D.push_back(i);
    }

    while(Q--) {
        cin >> t;
        if(t==1) {
            cin >> x >> c;
            x--; c--;

            ll c1 = D[x];
            ll i=x;
            while(D[i]==c1 && (i<N)) {
                D[i] = c;
                C[c1]--;
                C[c]++;
                i++;
            }

            i=x-1; 
            while(D[i]==c1 && (i>=0)) {
                D[i] = c;
                C[c1]--;
                C[c]++;
                i--;
            }
        }
        else {
            cin >> c;
            c--;
            cout << C[c] << '\n';
        }
    }

    return 0;
}