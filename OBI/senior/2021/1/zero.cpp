#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    stack<int> s;
    ll n, x, soma=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x==0 && s.size() != 0)
        {
            soma -= s.top();
            s.pop();
        }
        else if(x!=0)
        {
            soma += x;
            s.push(x);
        }
    }

    cout << soma << endl;
    return 0;
}