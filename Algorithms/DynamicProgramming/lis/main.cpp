/**
 *  @param  xs      Target Vector.
 *  @param  values  True if want values, indexes otherwise.
 *  @return         Longest increasing subsequence as values or indexes.
 *  https://judge.yosupo.jp/problem/longest_increasing_subsequence
 *  source: Yogi Nam
 *  Time complexity: O(Nlog(N))
*/
vll lis(const vll& xs, bool values) {
    assert(!xs.empty());
    vll ss, idx, pre(xs.size()), ys;
    for(ll i=0; i<xs.size(); i++) {
        // change to upper_bound if want not decreasing
        ll j = lower_bound(all(ss), xs[i]) - ss.begin();
        if (j == ss.size()) ss.eb(), idx.eb();
        if (j == 0) pre[i] = -1;
        else        pre[i] = idx[j - 1];
        ss[j] = xs[i], idx[j] = i;
    }
    ll i = idx.back();
    while (i != -1)
        ys.eb((values ? xs[i] : i)), i = pre[i];
    reverse(all(ys));
    return ys;
}