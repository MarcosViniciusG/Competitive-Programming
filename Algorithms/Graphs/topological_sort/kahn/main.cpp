// Na construcao da entrada, faca in[x].insert(y), out[y].insert(x)
vll kahn(ll n, set<ll> in[], set<ll> out[]) {
    vll o;
    priority_queue<ll, vll, greater<ll>> q;
    rep(i, 0, n) {
        if(in[i].empty())
            q.push(i);
    }
    while(!q.empty()) {
        ll u = q.top(); q.pop();
        for(auto e: out[u]) {
            in[e].erase(u);
            if(in[e].empty())
                q.push(e);
        }
        o.push_back(u);
    }
    return (o.size()==n ? o : vll()); // Retorna vazio, caso haja ciclo
}