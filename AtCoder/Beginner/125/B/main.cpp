#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Ci, Vi;
    cin >> N;

    int V[N];
    for(int i=0; i<N; i++) {
        cin >> V[i];
    }

    int C[N];
    for(int i=0; i<N; i++) {
        cin >> C[i];
    }

    int dif=0;
    for(int bit=0; bit<(1 << N); bit++) {
        int X=0;
        int Y=0;

        for(int i=0; i<N; i++) {
            if(bit & (1 << i)) {
                X+= V[i];
                Y+= C[i];
            }
        }

        dif = max(dif, X-Y);
    }

    cout << dif << endl;

    return 0;
}