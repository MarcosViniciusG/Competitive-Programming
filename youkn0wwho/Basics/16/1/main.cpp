#include <bits/stdc++.h>

using namespace std;

void solve(int N) {
    if(N!=0) {
        cout << "I love Recursion\n";
        solve(N-1);
    }
}

int main() {
    int N;
    cin >> N;

    solve(N);
    return 0;
}