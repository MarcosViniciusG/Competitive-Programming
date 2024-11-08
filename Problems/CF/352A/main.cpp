#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, a, i, j;
    vector<int> fives;
    vector<int> zeroes;

    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a) fives.push_back(a);
        else zeroes.push_back(a);
    }

    if(zeroes.size()==0)
    {
        cout << "-1\n";
    }
    else if(fives.size() < 9)
    {
        cout << "0\n";
    }
    else if(fives.size() >= 9)
    {
        string ans = "";
        for(i=0; i<(fives.size() / 9); i++)
        {
            for(j=0; j<9; j++)
            {
                ans += "5";
            }
        }

        for(i=0; i<zeroes.size(); i++)
            ans += "0";

        cout << ans << '\n';
    }
    return 0;
}