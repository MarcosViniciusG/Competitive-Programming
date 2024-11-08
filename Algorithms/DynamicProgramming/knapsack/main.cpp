#include <bits/stdc++.h>

using namespace std;

const int N=100;
const int W=100000;

bool possible[W+1][N+1];

// Weight array
int w[N+1];
w[0] = 0;

// O(nW)
// possible(x, k) = possible(x-w[k], k-1) || possible(x, k-1)
// We can or not use the weight w[k]
int build() {
    possible[0][0] = true;
    for(int k=1; k<=n; k++) {
        for(int x=0; x<=W; x++) {
            if(x-w[k] >= 0) possible[x][k] |= possible[x-w[k]][k-1];
            possible[x][k] |= possible[x][k-1];
        }
    }
}