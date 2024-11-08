#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(sqrt(n))
bool isPrime(ll n)
{
    // Check if n is divisible by 2
    if(n!=2 && n % 2==0)
        return false;

    // Check only odd numbers
    for(ll d=3; d*d <= n; d+=2)
    {
        if(n % d==0)
            return false;
    }
    return n >= 2;
}