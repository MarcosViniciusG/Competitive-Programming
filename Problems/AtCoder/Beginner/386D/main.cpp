#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, xi, yi;
    char ci;
    cin >> n >> m;

    priority_queue<tuple<ll, ll, char>, vector<tuple<ll, ll, char>>, greater<tuple<ll, ll, char>>> pq;
    for(ll i=0; i<m; i++) {
        cin >> xi >> yi >> ci;
        pq.push({xi, yi, ci});
    }

    bool can = true;

    ll last_white_r=-1;
    ll last_white_c=-1;

    while(!pq.empty()) {
        tuple<ll, ll, char> t = pq.top(); pq.pop();
        char c = get<2>(t);
        ll row = get<0>(t);
        ll column = get<1> (t);
        
        if(c=='B' && last_white_r!=-1 && last_white_c <= column)
            can = false;
        else if(c=='W') {
            last_white_r = row;
            last_white_c = column;
        } 
    }

    cout << (can ? "Yes" : "No") << '\n';
    return 0;
}