/**
 * @brief Returns the min cost hamiltonian cycles
 * @param i Current city
 * @param mask Visited cities
 * Can be modified to return the max cost
 * Can include only a set qnt of cities
 * Can modify the dist graph to a non-complete graph:
 * Set dist[i][j] = INT_MAX
 */

int tsp(int i, int mask) {
    if(mask == (1 << n) - 1)
        return dist[i][0];
    
    if(st[i][mask] == -1)
        return st[i][mask];
    
    int res = INT_MAX;
    for(int j=0; j<n; j++) {
        if(mask & (1 << j))
            continue;
        res = min(res, tsp(j, mask | (1 << j), n) + dist[i][j]);
    }

    return (st[i][mask] = res);
}