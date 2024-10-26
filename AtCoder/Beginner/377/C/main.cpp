#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    ll N, M, ak, bk; 
    cin >> N >> M;
    
    ll total = N*N;

    set<pll> s;
    for(ll i=0; i<M; i++) {
        cin >> ak >> bk;
        s.insert(make_pair(ak, bk));

        if((ak-2 > 0) && (bk+1 <= N))
            s.insert(make_pair(ak-2, bk+1));

        if((ak-2 > 0) && (bk-1 > 0))
            s.insert(make_pair(ak-2, bk-1));

        if((ak+2 <= N) && (bk+1 <= N))
            s.insert(make_pair(ak+2, bk+1));

        if((ak+2 <= N) && (bk-1 > 0))
            s.insert(make_pair(ak+2, bk-1));

        if((ak+1 <=N) && (bk+2 <= N))
            s.insert(make_pair(ak+1, bk+2));

        if((ak+1 <= N) && (bk-2 > 0))
            s.insert(make_pair(ak+1, bk-2));

        if((ak-1 > 0) && (bk+2 <= N))
            s.insert(make_pair(ak-1, bk+2));

        if((ak-1 > 0) && (bk-2 > 0))
            s.insert(make_pair(ak-1, bk-2));

    }

    cout << total - s.size() << '\n';

    return 0;
}