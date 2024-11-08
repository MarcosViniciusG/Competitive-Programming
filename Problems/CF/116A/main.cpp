#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, a, b, current=0, cap=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        current += b - a;

        if(current > cap) cap = current;
    }

    cout << cap << endl;
    return 0;
}