// O(D^3(N + Qlog(N)))
// D = 3
// All paths in interval with updates (segment tree, matrix)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>; 

vvll t[200001];
const ll MODM = 998244353;

vvll multiply(const vvll &a, const vvll &b) {
    vvll res(3, vll(3, 0));
    for(ll i=0; i<3; i++)
    for(ll j=0; j<3; j++)
    for(ll k=0; k<3; k++)
        res[i][j] = (res[i][j] + ((a[i][k] * b[k][j]) % MODM)) % MODM;

    return res;
}

// O(n)
void build(const vector<vvll> &xs, ll v, ll tl, ll tr) {
    if(tl==tr) t[v] = xs[tl]; 
    else {
        ll tm = (tl+tr) / 2;
        build(xs, v+1, tl, tm);
        build(xs, v+2*(tm-tl+1), tm+1, tr);
        // Merge function
        t[v] = multiply(t[v+1], t[v+2*(tm-tl+1)]);
    }
}

// O(log n)
vvll que(ll v, ll tl, ll tr, ll l, ll r) {
    if(l > r) {
        vvll i(3, vll(3, 0));
        i[0][0] = i[1][1] = i[2][2] = 1;
        return i;
    }
    if(l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;

    return multiply
    (
        que(v+1, tl ,tm, l, min(r, tm)), 
        que(v+2*(tm-tl+1), tm+1, tr, max(l, tm+1), r)
    );
}

// O(log n)
void update(ll v, ll tl, ll tr, ll pos,const vvll &new_val) {
    if(tl == tr)
        t[v] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v+1, tl, tm, pos, new_val);
        else
            update(v+2*(tm-tl+1), tm+1, tr, pos, new_val);
        t[v] = multiply(t[v+1], t[v+2*(tm-tl+1)]);
    }

}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    ll mi;
    vector<vvll> xs;
    for(ll i=0; i<n; i++) {
        vvll v(3, vll(3)); 
        for(ll j=0; j<3; j++) {
            cin >> mi;
            if(j==0) 
                v[0][1] = v[1][0] = mi;
            else if(j==1)
                v[0][2] = v[2][0] = mi;
            else
                v[1][2] = v[2][1] = mi;
        }
        v[0][0] = v[1][1] = v[2][2] = 1;
        xs.push_back(v);
    }

    map<char, ll> mp;
    mp['R'] = 0;
    mp['Q'] = 1;
    mp['I'] = 2;

    build(xs, 1, 0, n-1);    
    while(q--) {
        ll t, l, r, d, x;
        char a, b;
        cin >> t >> a >> b;
        if(t==1) {
            cin >> l >> r;
            l--; r--;
            vvll res = que(1, 0, n-1, l ,r);
            cout << res[mp[a]][mp[b]] << '\n';
        }
        else {
            cin >> d >> x;
            d--;
            xs[d][mp[a]][mp[b]] = xs[d][mp[b]][mp[a]] = x;
            update(1, 0, n-1, d, xs[d]);
        }
    }

    return 0;
}