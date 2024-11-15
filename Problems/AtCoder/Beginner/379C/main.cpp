#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    ll N, M, Xi, Ai;
    cin >> N >> M;

    vpll pares;

    for(ll i=0; i<M; i++) {
        cin >> Xi;
        pares.push_back(make_pair(Xi, 0));
    }

    ll soma=0;
    for(ll i=0; i<M; i++) {
        cin >> Ai;
        pares[i].second = Ai;
        soma += Ai;
    }

    sort(pares.begin(), pares.end());
    if(soma!=N || (pares[0].first!=1)) {
        cout << -1 << '\n';
        return 0;
    }

    ll no=0;
    if(pares[M-1].first!=N) { 
        pares.push_back(make_pair(N, 1));
    }

    for(ll i=0; i<pares.size()-1; i++) {
        pll par = pares[i];
        pll next_par = pares[i+1];
        ll diff = next_par.first - par.first;

        ll sobra = par.second - diff;

        if(sobra < 0) {
            no = -1;
            break;
        }

        pares[i+1].second += sobra;
        no += (sobra*diff);
        no += ((diff-1) * (1 + (diff-1)))/2;
    }

    cout << no << '\n';
    return 0;
}