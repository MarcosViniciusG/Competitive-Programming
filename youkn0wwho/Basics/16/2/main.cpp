#include <bits/stdc++.h>

using namespace std;

void solve(int N, int n) {
    if(n>-1) {
        cout << N-n << endl;
        solve(N, n-1);
    }

}

int main() {
    int N;
    cin >> N;
    solve(N, N-1);

    return 0;
}