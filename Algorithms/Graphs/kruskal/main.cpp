#define tll   tuple<ll, ll, ll>
#define vtll  vector<tll>
struct DSU {
    vll parent, size;
    DSU(ll sz) : parent(sz), size(sz, 1) { iota(all(parent), 0); }

    ll find(ll x) {
        assert(0 <= x && x < parent.size());
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void merge(ll x, ll y) {
        ll a = find(x), b = find(y);
        if (size[a] > size[b]) swap(a, b);
        parent[a] = b;
        if (a != b) size[b] += size[a], size[a] = 0;
    }
    bool same(ll x, ll y) { return find(x) == find(y); }
};
vtll kruskal(vtll& edges, ll n) {
    DSU dsu(n);
    vtll mst;
    sort(all(edges));  // change order if want maximum
    for (auto [w, u, v] : edges) if (!dsu.same(u, v)) {
        dsu.merge(u, v);
        mst.eb(w, u, v);
    }
    return mst;
}