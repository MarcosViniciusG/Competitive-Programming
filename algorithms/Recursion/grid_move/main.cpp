#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m) {
    if(n==1 || m==1)
        return 1;
    else
        return solve(n-1, m) + solve(n, m-1);
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;

    return 0;
}