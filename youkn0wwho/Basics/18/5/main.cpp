#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisors(ll n) {
    vector<ll>divs;

    for(ll i=1; i*i<=n; i++) {
        if(n % i==0) {
            if(n / i==i)
                divs.push_back(i);
            else {
                divs.push_back(i);
                divs.push_back(n / i);
            }

        }
    }

    return divs;
}

ll gcd(ll a, ll b) {
    if(a==0)
        return b;
    return gcd(b % a, a);
}

// Best answer is b mod a==0
// Else answer is n and n-1
// If b mod a = 0, n mod a = 0, because n = a + b
// If n is even, the best answer is n / 2
int main() {
    int t;
    ll n;

    cin >> t;
    while(t--) {
        cin >> n;
        if((n & 1)==0) {
            cout << n/2 << " " << n/2 << endl;
            continue;
        }

        bool found = false;
        ll mgcd=0;
        ll a=0;
        for (auto div: divisors(n)) {
            if(div < n && (n % div == 0)) {
                if(gcd(n, div) > mgcd) {
                    mgcd = gcd(n, div);
                    a = div;
                }
            }
        }      

        cout << n - a << " " << a << endl;  
    }

    return 0;
}