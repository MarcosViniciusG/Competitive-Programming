/**
 * @brief Makes change for a given amount using a greedy approach.
 * Assumes the coin denominations 'xs' are sorted in descending order.
 */
vll greedy(ll x, ll N, const vll &xs) 
{
    vll res(N, 0);
    for(ll i=0; i<N; i++)
    {
        auto q = x / xs[i];
        x -= q*xs[i];
        res[i] = q;
    }

    return res;
}

/**
 * @brief Calculates the total monetary value of a given combination of coins.
 */
ll value(const vll &M, ll N, const vll &xs) 
{
    ll res=0;
    for(ll i=0; i<N; i++) 
        res += M[i]*xs[i];
    return res;
}

/**
 * @brief Finds the smallest amount of money for which the greedy algorithm fails
 * to produce an optimal solution (i.e., the minimum number of coins).
 * This is based on a known algorithm for testing if a coin system is "canonical".
 */
ll min_counterexample(ll N, const vll &xs)
{
    if(N <= 2)
        return -1;
    
    ll ans=oo;

    for(ll i=N-2; i>=0; --i) {
        auto g = greedy(xs[i]-1, N, xs);

        vll M(N, 0);

        for(ll j=0; j<N; ++j)
        {
            M[j] = g[j] + 1;
            auto w = value(M, N, xs);
            auto G = greedy(w, N, xs);

            auto x = accumulate(M.begin(), M.end(), 0);
            auto y = accumulate(G.begin(), G.end(), 0);

            if(x < y)
                ans = min(ans, w);
            
            M[j]--;
        }
    }

    return ans == oo ? -1 : ans;
}