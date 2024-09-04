#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(a==0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b, ll hcf) {
    return a / hcf * b;
}

int main() {
    ll t, a, b;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        ll hcf = gcd(a, b);

        cout << lcm(a, b, hcf) << " " << hcf << endl;
    }

    return 0;
}