#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll t, n;
    cin >> t;

    while(t--) {
        ll sumPa, sumPg=0;
        cin >> n;

        sumPa = n*(1 + n) / 2;
        for(ll i=1; i<=n; i*=2) {
            sumPg -= i;
        }

        cout << sumPa + sumPg*2 << endl;
    }

    return 0;
}