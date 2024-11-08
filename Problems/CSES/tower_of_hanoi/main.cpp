#include <bits/stdc++.h>

using namespace std;

void solve(int n, int start, int end) {
    if(n==1)
        cout << start << " " << end << endl;
    else
    {
        int other = 6-(start+end);
        solve(n-1, start, other);
        cout << start << " " << end << endl;
        solve(n-1, other, end);
    }
    

}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;

    solve(n, 1, 3);

    return 0;
}