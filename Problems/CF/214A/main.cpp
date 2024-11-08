#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, m, a, b, n1, n2, other;
    cin >> n >> m;
    vector<pair<ll, ll>> solutions;
    for(a=0; a<=1000; a++)
    {
        for(b=0; b<=1000; b++)
        {
            bool flag = false;
            if(a + (b*b) == n)
            {
                n1 = a;
                n2 = b;
                other = m;
                flag = true;
            }
            else if((a*a) + b == m)
            {
                n1 = b;
                n2 = a;
                other = n;
                flag = true;
            }

            if(flag && (n1*n1) + n2 == other)
                solutions.push_back(make_pair(a, b));
        }
    }

    // for(auto e: solutions)
    // {
    //     cout << e.first << " " << e.second << endl;
    // }

    cout << solutions.size() << endl;
}