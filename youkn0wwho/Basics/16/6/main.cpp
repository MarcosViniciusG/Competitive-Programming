#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
    int Ai;
    if(N!=0) {
        cin >> Ai;
        return Ai + solve(N-1);
    }
    
    return 0;
}

int main() {
    int T;
    cin >> T;

    int N;
    for(int i=0; i<T; i++) {
        cin >> N;
        cout << "Case " << i+1  << ": " << solve(N) << endl;
    }

    return 0;
}