#include <bits/stdc++.h>

using namespace std;

#define ll int
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define eb emplace_back

template <typename T, typename Op = function<T(T, T)>>
struct Segtree {
    Segtree(ll sz, T def, Op f) : seg(4 * sz, def), lzy(4 * sz), n(sz), DEF(def), op(f) {}
    
    T updQry(ll i, ll j, T x = INT_MIN, ll l = 0, ll r = -1, ll no = 1) {
        if (r == -1) r = n - 1;
        if (lzy[no]) unlazy(l, r, no);
        if (j < l or i > r) return DEF;
        if (i <= l and r <= j) {
            if (x != INT_MIN) {
                lzy[no] += x;
                unlazy(l, r, no);
            }
            return seg[no];
        }
        ll m = (l + r) / 2;
        T q = op(updQry(i, j, x, l, m, 2 * no), updQry(i, j, x, m + 1, r, 2 * no + 1));
        seg[no] = op(seg[2 * no], seg[2 * no + 1]);
        return q;
    }

private:
    void unlazy(ll l, ll r, ll no) {
        if (seg[no] == DEF) seg[no] = 0;
        seg[no] += (r - l + 1) * lzy[no];
        if (l < r) {
            lzy[2 * no] += lzy[no];
            lzy[2 * no + 1] += lzy[no];
        }
        lzy[no] = 0;
    }

    vector<T> seg, lzy;
    ll n;
    T DEF = 0;
    Op op;
};

template <typename T, typename Op = function<T(T, T)>>
struct HLD {
    HLD(vvll& g, T def, Op f) : seg(g.size(), def, f), op(f) {
        idx = subtree = parent = head = vll(g.size());
        auto build = [&](auto& self, ll u = 1, ll p = 0) -> void {
            idx[u] =  timer++, subtree[u] = 1, parent[u] = p;
            for (ll& v : g[u]) if (v != p) {
                head[v] = (v == g[u][0] ? head[u] : v);
                self(self, v, u);
                subtree[u] += subtree[v];
                if (subtree[v] > subtree[g[u][0]] or g[u][0] == p)
                    swap(v, g[u][0]);
            }
            if (p == 0) {
                timer = 0;
                self(self, head[u] = u, -1);
            }
        };
        build(build);
    }

    ll setQueryPath(ll u, ll v, ll x = INT_MIN) {
        assert(1 <= u and u < idx.size() and 1 <= v and v < idx.size());
        if (idx[u] < idx[v]) swap(u, v);
        if (head[u] == head[v]) return seg.updQry(idx[v], idx[u], x);
        return op(seg.updQry(idx[head[u]], idx[u], x), setQueryPath(parent[head[u]], v, x));
    }

    Segtree<T> seg;
    vll idx, subtree, parent, head;
    ll timer = 0;
    Op op;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vvll g(n + 1);
    rep(i, 0, n - 1) {
        ll u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    HLD hld(g, 0, [](ll a, ll b) { return a + b; });

    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        hld.setQueryPath(a, b, 1);
        cout << hld.setQueryPath(c, d) << '\n';
        hld.setQueryPath(a, b, -1);
    }
}