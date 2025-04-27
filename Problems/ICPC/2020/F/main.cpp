#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()

signed main() 
{
    string s;
    cin >> s;

    int gl=0, pl=0, gr=0, pr=0;
    bool left = true;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'Q')
        {
            if(i+1 == s.size())
            {
                if(gr < gl)
                {
                    cout << gl << " (winner) - " << gr << '\n';
                }
                else cout << gl << " - " << gr << " (winner)\n";
            }
            else
            {
                if(left)
                {
                    cout << gl << " (" << pl << "*)" <<  " - " << gr << " (" << pr << ")" << '\n';
                }
                else
                {
                    cout << gl << " (" << pl << ")" <<  " - " << gr << " (" << pr << "*)" << '\n';
                }
            }
        }

        else
        {
            if(left)
            {
                if(s[i]=='S') pl++;
                else
                {
                    pr++;
                    left=false;
                }
            }

            else
            {
                if(s[i]=='S') pr++;
                else
                {
                    pl++;
                    left=true;
                }
            }

            if(pr == 10 || (pr >= 5 && pr-pl >= 2))
            {
                gr++;
                pl=0;
                pr=0;
            } 
            else if(pl == 10 || (pl >= 5 && pl-pr >= 2))
            {
                gl++;
                pl=0;
                pr=0;
            } 
        }
    }

    return 0;
}