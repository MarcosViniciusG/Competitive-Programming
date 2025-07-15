/**
 * @brief Calculates the minimum number of coins required to make a target amount using dynamic programming (memoization).
 * @param m The target amount of money to reach.
 * @param cs Coins
 * @return The minimum number of coins needed to sum up to 'm'
 */
ll coin_change(ll m, const vll &cs)
{
    if (m == 0)
        return 0;

    if (st[m] != -1)
        return st[m];

    auto res = oo;
    for (auto c : cs)
        if (c <= m)
            res = min(res, coin_change(m - c, cs) + 1);
    return st[m] = res;
}