#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, W;
    cin >> n >> W;

    vector<ll> w(n), v(n);
    for(int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }


    ll f[W+1];
    memset(f, 0, sizeof(f));

    ll chosen[W+1];
    memset(chosen, -1, sizeof(chosen));

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            if(f[j] < (f[j-w[i]] + v[i])) {
                f[j] = (f[j - w[i]] + v[i]);

                chosen[j] = i;
            }
        }
    }

    cout << "Max: " << f[W] << '\n';
    vector<bool> items (n, false);

    while(W > 0 && chosen[W]!=-1) {
        int i = chosen[W];
        items[i] = true;
        W -= w[i];
    }

    for(int i=0; i<n; i++) {
        if(items[i])
            cout << v[i] << " ";
    }
    cout << '\n';
}