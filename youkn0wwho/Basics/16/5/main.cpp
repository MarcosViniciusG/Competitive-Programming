#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
    if(N==1)
        return 0;
    else if(N==2)
        return 1;
    else
        return solve(N-1) + solve(N-2);
}

int main() {
    int N;
    cin >> N;

    cout << solve(N) << endl;

    return 0;
}