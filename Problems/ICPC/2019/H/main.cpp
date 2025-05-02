#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;

    int t = n*m;

    for(int i = 1; i < 10; i++)
    {
        int num = (t*i)/10;
        if((t*i)%10) num+=1;
        cout << num << " ";
    }
    cout << '\n';
}