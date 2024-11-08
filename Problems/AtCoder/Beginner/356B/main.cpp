#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    ll A[M];
    for(int i=0; i<M; i++) {
        cin >> A[i];
    }

    ll X[N][M];

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> X[i][j];
        }
    }

    bool can = true;
    for(int j=0; j<M; j++) {
        ll totali=0;

        for(int i=0; i<N; i++) {
            totali += X[i][j];
        }

        if(totali < A[j])
            can = false;
    }

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}