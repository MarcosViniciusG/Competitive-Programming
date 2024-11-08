#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll n5=0;
    for(ll i=5; i<=n; i+=5) {
        ll new_n5=i;
        while(new_n5 % 5==0) {
            n5++;
            new_n5/=5;
        }
    }

    cout << n5 << '\n';
    return 0;
}