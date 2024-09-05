#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dices[]={1, 2, 3, 4, 5, 6};

int main() {
    ll n;
    cin >> n;

    ll ways[n+1] = {0};
    ways[0] = 1;
    for(int x=1; x<=n; x++) {

        for(auto d: dices) {
            if(x - d >= 0) {
                ways[x] += ways[x-d];
                ways[x] %= ll(1e9+7);
            }
        }
    }

    cout << ways[n] << endl;

    return 0;
}
