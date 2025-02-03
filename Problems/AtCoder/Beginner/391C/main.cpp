#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;

    unordered_map<ll, ll> nests;
    unordered_map<ll, ll> pigeons;
    ll moreThanOne=0;

    for(ll i=0; i<N; i++) {
        nests[i]=1;
        pigeons[i] = i;
    }

    ll T, P, H;
    while(Q--)
    {
        cin >> T;
        if(T==1) {
            cin >> P >> H;
            P--;
            H--;
            nests[pigeons[P]]--;
            if(nests[pigeons[P]]==1)
                moreThanOne--;

            ll prev = nests[H];
            nests[H]++;
            if(prev==1)
                moreThanOne++;

            pigeons[P] = H;
        }
        else 
            cout << moreThanOne << '\n';
    }
    
    return 0;
}