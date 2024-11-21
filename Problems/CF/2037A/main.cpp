#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n, ai;
    cin >> t;
    while(t--) {
        cin >> n;
        int counter[n] = {0};

        for(int i=0; i<n; i++) {
            cin >> ai;
            counter[ai-1]++;
        }

        int score=0;
        for(auto e: counter)
            score += (e/2);
        
        cout << score << '\n';
    }

    return 0;
}