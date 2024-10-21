#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    ll S, Ai;

    cin >> N >> S;

    vector<ll> A;

    for(int i=0; i<N; i++) {
        cin >> Ai;
        A.push_back(Ai);
    }

    bool b = false;
    for(int bit=0; bit<(1 << N); bit++) {
        ll sum=0;

        for(int i=0; i<N; i++) {
            if((bit & (1 << i)) != 0) {
                sum += A[i];
            }
        }

        if(sum == S) {
            b=true;
            break;
        }

    }

    if(b)
        cout << "YES\n";
    else
        cout << "NO\n";

}