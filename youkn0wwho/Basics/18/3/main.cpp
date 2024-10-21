#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Answer is number of divisors of g

ll gcd(ll a, ll b) {
    if(a==0)
        return b;
    return gcd(b % a, a);
}

ll ndivs (ll x) {
    ll n=0;
    for(ll i=1; i*i<=x; i++) {
        if(x % i==0) {
            n++;
            if(x / i !=i)
                n++;
        }
    }

    return n;
} 

int main() {
    ll n;
    cin >> n;
    ll a[n];

    cin >> a[0];
    ll g = a[0];

    for(ll i=1; i<n; i++) {
        cin >> a[i];
        g = gcd(a[i], g);
    }

    cout << ndivs(g) << endl;

    return 0;
}