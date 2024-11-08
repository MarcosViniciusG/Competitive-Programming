#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gridTraveler(int y, int x, ll memo[101][101] ) {
    if(y==1 && x==1) return memo[y][x] = 1;
    if(y==0 || x==0) return memo[y][x] = 0;

    if(memo[y-1][x] == -1 || memo[y][x-1] == -1) 
        memo[y-1][x] = gridTraveler(y-1, x, memo);

    if(memo[y][x-1] == -1)
        memo[y][x-1] = gridTraveler(y, x-1, memo);

    return memo[y][x] = memo[y-1][x] + memo[y][x-1];
}

int main() {
    ll memo[101][101];

    memset(memo, -1, sizeof(memo));

    cout << gridTraveler(2, 2, memo) << endl;
    cout << gridTraveler(2, 3, memo) << endl;
    cout << gridTraveler(3, 3, memo) << endl;
    cout << gridTraveler(16, 16, memo) << endl;
    cout << gridTraveler(100, 100, memo) << endl;

    return 0;
}