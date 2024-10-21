#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, a, b, c, fib, fib1=1, fib2=0, fib3, fib4, i, soma=0;
    bool existe = false;
    cin >> n;

    if(n==0)
    {
        a = 0;
        b = 0;
        c = 0;
        existe = true;
    }
    else if(n==1)
    {
        a = 1;
        b = 0;
        c = 0;
        existe = true;
    }
    else if(n==2)
    {
        a = 1;
        b = 1;
        c = 0;
        existe = true;
    }
    else
    {
        while(fib1+fib2<=n)
        {
            fib = fib1 + fib2;
            if(fib==n)
            {
                a = fib2;
                b = fib2;
                c = fib3;
                existe = true;
            }

            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib;
        }
    }

    if(existe)
        cout << a << " " << b << " " << c << endl;
    else
        cout << "I'm too stupid to solve this problem\n";
}