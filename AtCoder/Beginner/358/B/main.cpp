#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll N, A, Ti;

    cin >> N >> A;

    ll pendingtime=0;
    for(ll i=0; i<N; i++) {
        cin >> Ti;

        pendingtime = max(pendingtime-Ti, ll(0));
        
        ll finishtime = (Ti + pendingtime + A);
        cout << finishtime << endl;

        pendingtime = finishtime;
    }

    return 0;
}