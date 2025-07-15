ll lis(vll const& a) {
    ll n = a.size();
    const ll INF = 1e9;
    vll d(n+1, INF);
    d[0] = -INF;

    for (ll i = 0; i < n; i++) {
        ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    ll ans = 0;
    for (ll l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}