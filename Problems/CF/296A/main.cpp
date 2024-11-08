#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a;
    cin >> n;
    int C[1001] = {0};

    for(int i=0; i<n; i++)
    {
        cin >> a;
        C[a]++;
    }

    bool can = true;
    for(int i=1; i<1001 && can; i++)
    {
        if(C[i] > ((n+1) / 2))
            can=false;
    }

    if(!can)
        cout << "NO\n";
    else
        cout << "YES\n";
}