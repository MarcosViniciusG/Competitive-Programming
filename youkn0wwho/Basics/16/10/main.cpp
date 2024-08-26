#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int c) {
    if(a==0 && b==0)
        return;

    if(a==1 && c==0) {
        cout << "1 3\n";
        solve(a-1, b, 1);
    }
    

}

int main() {
    int n;
    cin >> n;

    solve(n, 0, 0);

    return 0;
}