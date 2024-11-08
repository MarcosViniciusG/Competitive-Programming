#include <bits/stdc++.h>

using namespace std;
void solve(int n) {
    int nc = n / 4;
    int nch = (n - (nc*4)) / 2;

    cout << nc + nch << endl;
}

int main() {
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        solve(n);
    }

    return 0;
}