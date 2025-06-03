
ll kadane(const vll &a) {
    ll n = a.size();
    ll ans = a[0], ans_l = 0, ans_r = 0;
    ll sum = 0, minus_pos = -1;

    for (ll r = 0; r < n; ++r) {
        sum += a[r];
        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }

    return ans;
}