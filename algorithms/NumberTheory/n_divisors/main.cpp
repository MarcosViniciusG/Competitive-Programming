#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O (n^1/2)
ll n_divisors(ll n) {

    ll c;
    if(n==1)
        c=1;
    else
        c=2;

    for(ll i=2; i*i <= n; i++) {
        if(n % i==0) {
            if(i*i != n)
                c+=2;
            else
                c++;
        }
    }
        
    return c;
}

// O(n^1/3)
ll n_divisors(ll n) {

    ll c;
    if(n==1)
        c=1;
    else
        c=2;

    for(ll i=2; i*i <= n; i++) {
        if(n % i==0) {
            if(i*i != n)
                c+=2;
            else
                c++;
        }
    }
        
    return c;
}