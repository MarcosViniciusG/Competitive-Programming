#include <bits/stdc++.h>

using namespace std;

long long sm=0;

void solve(int start, int end) {
        if(start>=end)
            sm++;
        else {
            if(start+1 <= end)
                solve(start+1, end);
            if(start+2 <= end)
                solve(start+2, end);
            if(start+3 <= end)
                solve(start+3, end);
        }
}

int main() {
    int S, E;
    cin >> S >> E;

    solve(S, E);

    cout << sm << endl;

    return 0;
}