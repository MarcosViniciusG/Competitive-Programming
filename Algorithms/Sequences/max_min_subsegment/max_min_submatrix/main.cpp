ll MSR(ll n, ll m, const vvll &a) {
    ll ans = -LLONG_MAX;

    for(ll i=0; i<m; i++) {
        vll r(n+1, 0);
        
        for(ll j=i; j<m; j++) {
            for(ll k=0; k<n; k++)
                r[k] += a[k][j];

            ans = max(ans, kadane(n, r));
        }
    }

    return ans;
}