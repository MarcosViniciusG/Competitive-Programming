/**
 *  @param  g  Graph (w, v).
 *  @param  s  Starting vertex.
 *  @return    Vectors with smallest distances from every vertex to s and the paths.
 *  Na construcao do grafo, nos pares, primeiro vem o peso
 *  e depois o vertice
*/
pair<vll, vll> dijkstra(const vvpll& g, ll s) {
    vll ds(g.size(), LLONG_MAX), pre = ds;
    priority_queue<pll, vpll, greater<>> pq;
    ds[s] = 0, pq.emplace(ds[s], s);
    while (!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();
        if (t > ds[u]) continue;
        for (auto [w, v] : g[u])
            if (t + w < ds[v]) { // relaxamento
                ds[v] = t + w, pre[v] = u;
                pq.emplace(ds[v], v);
            }
    }
    return { ds, pre };
}
vll get_path(const vll& pre, ll u) {
    vll p;
    while (u != LLONG_MAX) {
        p.eb(u), u = pre[u];
    }
    reverse(all(p));
    return p;
}