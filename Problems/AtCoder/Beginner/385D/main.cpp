#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    ll N, M, Sx, Sy, Xi, Yi, Ci;
    char Di;
    cin >> N >> M >> Sx >> Sy;

    // Y of houses at x
    map<ll, set<ll>> mpx;

    // X of houses at y
    map<ll, set<ll>> mpy;

    for(ll i=0; i<N; i++) {
        cin >> Xi >> Yi;
        mpx[Xi].insert(Yi);
        mpy[Yi].insert(Xi);
    }

    map<char, pll> dir;
    dir['U'] = {0, 1};
    dir['D'] = {0, -1};
    dir['L'] = {-1, 0};
    dir['R'] = {1, 0};
        
    ll counter = 0;
    for(ll i=0; i<M; i++) {
        cin >> Di >> Ci;
        pll moves = dir[Di];
        ll xi = (Sx + moves.first * Ci);
        ll yi = (Sy + moves.second * Ci);
        
        if(Sy != yi) {
            ll objeto, parada;
            if(Sy > yi) {
                objeto = yi;
                parada = Sy;
            }
            else {
                objeto = Sy;
                parada = yi;
            }
            auto it=mpx[Sx].lower_bound(objeto);
            while(!mpx[Sx].empty() && (*it) <= parada && it!=mpx[Sx].end()) {
                mpy[*it].erase(Sx);
                mpx[Sx].erase(*it);
                it=mpx[Sx].lower_bound(objeto);
                counter++;
            }
        }
        else if(Sx != xi) {
            ll objeto, parada;
            if(Sx > xi) {
                objeto = xi;
                parada = Sx;
            }
            else {
                objeto = Sx;
                parada = xi;
            }
            auto it=mpy[Sy].lower_bound(objeto);
            while(!mpy[Sy].empty() && (*it) <= parada && it!=mpy[Sy].end()) {
                if(mpx.find(*it) != mpx.end())
                    mpx[*it].erase(Sy);
                else
                    break;
                mpy[Sy].erase(*it);
                it = mpy[Sy].lower_bound(objeto);
                counter++;
            }
        }

        Sx = xi;
        Sy = yi;
    }

    cout << Sx << " " << Sy << " " << counter << '\n';

    return 0;
}