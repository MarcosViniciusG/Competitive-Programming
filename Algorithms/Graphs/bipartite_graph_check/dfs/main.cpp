bool dfs(ll u, vll adj[], vll &color, ll c, ll &count0, ll &count1){
    vis[u] = true; 
    color[u] = c; 
    if(c==0) count0++; 
    else count1++; 
    for(auto &v: adj[u]){
      if(!vis[v]){
        if(!dfs(v, adj, color, c^1, count0, count1)) return false; 
      }else{
        if(color[u] == color[v]) return false; 
      }
    }
    return true; 
}