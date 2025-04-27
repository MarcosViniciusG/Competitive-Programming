    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vvvll vector<vvll>
    #define pll pair<ll, ll>
    #define all(xs) xs.begin(), xs.end()
    #define eb emplace_back

    signed main() {
        ll l, c;
        cin >> l >> c;

        vector<string> grid(l);
        for (ll i = 0; i < l; ++i)
            cin >> grid[i];

        ll n;
        cin >> n;
        vector<string> words(n);
        vvll words_hist(n, vll(26));
        for (ll i = 0; i < n; ++i) {
            cin >> words[i];
            for (char c : words[i])
                ++words_hist[i][c - 'A'];
        }
        sort(all(words_hist));

        vvvll ids(l, vvll(c, vll()));

        for (int len = 1; len <= 15; ++len)
            for (int i = 0; i < l; ++i) {
                vll freq(26);
                for (int r = 0; r < c; ++r) {
                    if (r - len >= 0)
                        --freq[grid[i][r - len] - 'A'];
                    ++freq[grid[i][r] - 'A'];
                    if (r - len + 1 < 0) continue;
                    ll idx = lower_bound(all(words_hist), freq) - words_hist.begin();
                    if (idx < words_hist.size() and freq == words_hist[idx])
                        for (int k = r - len + 1; k <= r; ++k)
                            ids[i][k].eb(idx);
                }
            }

        for (int len = 1; len <= 15; ++len)
            for (int r = 0; r < c; ++r) {
                vll freq(26);
                for (int i = 0; i < l; ++i) {
                    if (i - len >= 0)
                        --freq[grid[i - len][r] - 'A'];
                    ++freq[grid[i][r] - 'A'];
                    if (i - len + 1 < 0) continue;
                    ll idx = lower_bound(all(words_hist), freq) - words_hist.begin();
                    if (idx < words_hist.size() and freq == words_hist[idx])
                        for (int k = i - len + 1; k <= i; ++k)
                            ids[k][r].eb(idx);
                }
            }

        for (int i = 0; i < l; ++i) {
            for (int r = 0; r < c; ++r) {
                vll freq(26);
                for (int len = 1; len <= 15; ++len) {
                    if (i + len - 1 >= l or r + len - 1 >= c) break;
                    ++freq[grid[i + len - 1][r + len - 1] - 'A'];
                    ll idx = lower_bound(all(words_hist), freq) - words_hist.begin();
                    if (idx < words_hist.size() and freq == words_hist[idx])
                        for (int k = 0; k < len; ++k)
                            ids[i + k][r + k].eb(idx);
                }
            }
        }

        for (int i = 0; i < l; ++i) {
            for (int r = 0; r < c; ++r) {
                vll freq(26);
                for (int len = 1; len <= 15LL; ++len) {
                    if (i + len - 1 >= l or r - len + 1 < 0) break;
                    ++freq[grid[i + len - 1][r - len + 1] - 'A'];
                    ll idx = lower_bound(all(words_hist), freq) - words_hist.begin();
                    if (idx < words_hist.size() and freq == words_hist[idx])
                        for (int k = 0; k < len; ++k)
                            ids[i + k][r - k].eb(idx);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                sort(all(ids[i][j]));
                ids[i][j].erase(unique(all(ids[i][j])), ids[i][j].end());
                // cout << ids[i][j][0] << ' ';
                // cout << ids[i][j].size() << ' ';
                ans += ids[i][j].size() >= 2;
            }
            // cout << '\n';
        }
        cout << ans << '\n';
    }