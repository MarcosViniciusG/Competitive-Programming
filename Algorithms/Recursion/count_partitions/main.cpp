#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m) {
    if(n==0)
        return 1;
    else if(m==0 || n<0)
        return 0;
    else {
        int r = n-m;
        return solve(n, m-1) + solve(r, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;
    return 0;
}