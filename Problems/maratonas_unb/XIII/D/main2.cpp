// O(D^3(N + Qlog(N)))
// D = 3
// All paths in interval with updates (segment tree, matrix)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>; 

const ll MODM = 998244353;

vvll unit(3, vll(3));

vvll multiply(const vvll &a, const vvll &b) {
    vvll res(3, vll(3, 0));
    for(ll i=0; i<3; i++)
    for(ll j=0; j<3; j++)
    for(ll k=0; k<3; k++)
        res[i][j] = (res[i][j] + ((a[i][k] * b[k][j]) % MODM)) % MODM;

    return res;
}

struct Tree {
	typedef vvll T;
	T f(const T &a, const T &b) { return multiply(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos*2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

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

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
        if(i==j) unit[i][j] = 1;
        else unit[i][j] = 0;

    map<char, ll> mp;
    mp['R'] = 0;
    mp['Q'] = 1;
    mp['I'] = 2;

    Tree st(n+1);
    for (int i = 0; i < n; ++i) {
        st.update(i, xs[i]);
    }

    while(q--) {
        ll t, l, r, d, x;
        char a, b;
        cin >> t >> a >> b;
        if(t==1) {
            cin >> l >> r;
            l--; r--;
            vvll res = st.query(l ,r+1);
            cout << res[mp[a]][mp[b]] << '\n';
        }
        else {
            cin >> d >> x;
            d--;
            xs[d][mp[a]][mp[b]] = xs[d][mp[b]][mp[a]] = x;
            st.update(d, xs[d]);
        }
    }

    return 0;
}