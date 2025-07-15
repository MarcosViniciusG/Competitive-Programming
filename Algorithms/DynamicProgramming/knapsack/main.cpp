/**
 * @brief Finds the maximum sum possible of the knapsack
 * Can solve subset sum problem (change max to logic OR)
 */
pair<ll, vll> knapsack(ll M, const vpll &cs)
{
    ll N = cs.size() - 1; // Elements start at 1

    for(ll i=0; i<=N; i++)
        st[i][0] = 0;
    
    for(ll m=0; m<=M; m++)
        st[0][m] = 0;
    
    for(ll i=1; i<=N; i++)
    {
        for(ll m = 1; m <= M; m++) 
        {
            st[i][m] = st[i-1][m];
            ps[i][m] = 0;
            auto [w, v] = cs[i];

            if(w <= M && st[i-1][m-w] + v > st[i][m])
            {
                st[i][m] = st[i-1][m-w] + v;
                ps[i][m] = 1;
            }
        }
    }

    // Elements recuperation
    ll m = M;
    vll is;

    for(ll i=N; i>=1; --i) 
    {
        if(ps[i][m])
        {
            is.push_back(i);
            m -= cs[i].first;
        }
    }

    reverse(is.begin(), is.end());

    return  {st[N][M], is};
}