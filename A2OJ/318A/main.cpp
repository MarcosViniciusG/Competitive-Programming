#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, k, num;
    cin >> n >> k;
    if(k <= ceil(n/2.0))
    {
        num = k*2 - 1;
    }
    else
    {
        num = (k - ceil(n/2.0)) * 2;
    }


    cout << num << endl;
}