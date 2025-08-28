#include <bits/stdc++.h>
 
using namespace std;
using pi = pair<int, int>;
using pii = pair<int, pi>;
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int x, n;
    cin >> x >> n;
    set<int> semaphores;
    semaphores.insert(0); semaphores.insert(x);
    int xi;
    int ans=x;
    int l=0;
    int r=x;
    for(int i=0; i<n; i++) {
        cin >> xi;
        semaphores.insert(xi);

        if(xi <= l || xi >= r) continue;

        ans=1;
        auto it = semaphores.begin();
        int prev = *it;
        it++;
        while(it != semaphores.end()) {
            ans = max(ans, *(it) - prev);
            if(*(it) - prev > ans) {
                ans = *(it) - prev;
                l = prev;
                r = *it;
            }

            prev = *it;
            it++;
        }
        cout << ans << ' ';
    }
    cout << '\n';
 
    return 0;
}