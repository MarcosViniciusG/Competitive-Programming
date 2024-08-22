#include <bits/stdc++.h>

using namespace std;
using ll = long long;
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

int main() {
    int n;
    cin >> n;

    int c = 0;
    for(int i=6; i<=n; i++) {
        int pc=0;
        for(int j=2; j<i; j++) {
            if ((i % j==0) && isPrime(j))
                pc++;
        }

        if(pc==2)
            c++;
    }

    cout << c << endl;
    return 0;
}