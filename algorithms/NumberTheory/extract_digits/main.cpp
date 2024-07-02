#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// For example, 42 will be 2 and 4
vector<ll> extractDigitsReverse(ll n) {
    vector<ll> digits;
    while(n > 0)
    {

        ll digit = n % 10;
        digits.push_back(digit);
        n /= 10;
    }

    return digits;
} 