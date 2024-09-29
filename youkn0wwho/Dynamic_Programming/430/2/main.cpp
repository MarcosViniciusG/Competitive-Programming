#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, W;

int main() {
    cin >> N >> W;
    int w[N+1];
    w[0] = 0;
    ll v[N+1];
    v[0] = 0;

    for(int i=1; i<=N; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    bool possible[N+1][W+1];
    memset(possible, 0, sizeof(possible));

    possible[0][0] = true;

    for(int k=1; k<=N; k++) {
        for(int x=0; x<=W; x++) {
            if(x-w[k] >= 0) 
                possible[k][x] |= possible[k-1][x-w[k]];

            possible[k][x] |= possible[k-1][x];
        }
    }

            // DEBUG 
    cout << "   ";
    for(int x=0; x<=W; x++) {
        cout << x << " ";
    }
    cout << endl;

    for(int k=0; k<=N; k++) {
        cout << k << ": ";
        for(int x=0; x<=W; x++) {
            cout << possible[k][x] << " ";
        }
        cout << endl;
    }

    return 0;
}