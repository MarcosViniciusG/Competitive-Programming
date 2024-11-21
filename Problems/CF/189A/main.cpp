#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, ribbon_sizes[3];
    cin >> n >> ribbon_sizes[0] >> ribbon_sizes[1] >> ribbon_sizes[2];

    int f[n+1];
    memset(f, 0, sizeof(f));
    for(auto siz: ribbon_sizes) {
        if(siz<=n)
            f[siz] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(auto siz: ribbon_sizes) {
            if(i-siz >= 0 && (f[i-siz]!=0)) {
                f[i] = max(f[i], f[i-siz]+1);
            }
        }
    }

    // for(auto e: f)
    //     cout << e << ' ';
    // cout << '\n';

    cout << f[n] << '\n';

    return 0;
}