#include <bits/stdc++.h>

using namespace std;
bool is_prime(int n)
{
    bool prime = true;
    if(n%2==0) prime = false;
    else
    {
        for(int i=(n/2 + 1); i > 2 && prime; i--)
        {
            if(n % i == 0) prime = false;
        }
    }

    return prime;
}

int main()
{
    int n, m;
    cin >> n >> m;
    bool apocalypse = false;
    for (int i=n+1; i<=m; i++)
    {
        if(is_prime(i))
        {
            if(i==m) apocalypse=true;
            else break;
        }
    }

    if(apocalypse) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}