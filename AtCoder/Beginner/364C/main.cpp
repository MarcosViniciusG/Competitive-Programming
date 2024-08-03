#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, X, Y, Ai, Bi;
    vector<ll> A;
    vector<ll> B;

    cin >> N >> X >> Y;

    for(ll i=0; i<N; i++) {
        cin >> Ai;
        A.push_back(Ai);
    }

    for(ll i=0; i<N; i++) {
        cin >> Bi;
        B.push_back(Bi);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll salt=0;
    ll swet=0;

    ll csalt=0;
    for(ll i=N-1; i>=0 && salt <= Y; i--) {
        salt += B[i];
        csalt++;
    }

    ll cswet=0;
    for(ll i=N-1; i>=0 && swet <= X; i--) {
        swet += A[i];
        cswet++;
    }

    cout << min(csalt, cswet) << endl;

    return 0;
}