#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> primeFactors(ll n) 
{ 
    vector<ll> primes;
    while (n % 2 == 0) 
    { 
        primes.push_back(2);
        n = n/2; 
    } 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            primes.push_back(i); 
            n = n/i; 
        } 
    } 

    if (n > 2) 
        primes.push_back(n);
    return primes;
}

int main()
{
    bool abc;
    ll T, N, n, X, Y, m;
    cin >> T;
    while(T--)
    {
        abc = false;
        cin >> N;
        if(N==3)
        {
            cout << -1 << endl;
            continue;
        }

        
        cout << X << " " << Y << endl;
    }


    return 0;
}