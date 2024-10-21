#include <bits/stdc++.h>

using namespace std;

int n_divisors_hash[1000010];

int n_divisors(int n) {
    if(n_divisors_hash[n]!=-1)
        return n_divisors_hash[n];

    int c;
    if(n==1)
        c=1;
    else
        c=2;

    for(int i=2; i*i <= n; i++) {
        if(n % i==0) {
            if(i*i != n)
                c+=2;
            else
                c++;
        }
    }
        
    n_divisors_hash[n]=c;
    return c;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    memset(n_divisors_hash, -1, sizeof(n_divisors_hash));

    int m = 1073741824;

    int sum=0;
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int k=1; k<=c; k++) {
                sum += (n_divisors(i * j* k) % m);
            }
        }
    }

    cout << sum << endl;
    return 0;
}