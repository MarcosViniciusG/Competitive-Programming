#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using d = double;

int main() {
    ll N;
    cin >> N;

    double Tx=0, Ty=0, Xi, Yi;
    d cost = 0;

    for(ll i=0; i<N; i++) {
        cin >> Xi >> Yi;
        cost += sqrt((Tx - Xi)*(Tx-Xi) + (Ty - Yi)*(Ty - Yi));
        Tx = Xi; Ty = Yi;
    }

    cost += sqrt((0 - Xi)*(0-Xi) + (0 - Yi)*(0 - Yi));
    cout << setprecision(20) << cost << endl;

    return 0;
}