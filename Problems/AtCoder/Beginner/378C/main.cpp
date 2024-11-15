#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N;
    cin >> N;

    map<ll, ll> occurred;
    ll A[N];
    ll B[N];

    for(ll i=0; i<N; i++) {
        cin >> A[i];
        if(occurred.find(A[i])==occurred.end()) {
            B[i] = -1;
        }
        else {
            B[i] = occurred[A[i]];
        }

        occurred[A[i]] = i+1;
        cout << B[i] << ' ';
    }
    cout << '\n';

    return 0;
}