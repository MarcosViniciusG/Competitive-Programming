#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    
    return gcd(b % a, a);
}

// O(NlogA1 + NlogAN)
int main() {
    ll N;
    cin >> N;

    ll A[N];

    ll L[N+1];
    ll R[N+1];

    L[0] = 0;
    R[N] = 0;

    for(ll i=0; i<N; i++) {
        cin >> A[i];
        L[i+1] = gcd(L[i], A[i]);
    }

    for(ll i=N-1; i>ll(-1); i--) {
        R[i] = gcd(R[i+1], A[i]);
    }

    ll mgcd = 0;
    for(ll i=1; i<=N; i++) {
        // cout << L[i] << " " << R[i] << endl;
        mgcd = max(mgcd, gcd(L[i-1], R[i]));
    }

    cout << mgcd << endl;

    return 0;
}