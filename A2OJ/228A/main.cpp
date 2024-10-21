#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll rep=0, s[4], mask[4]={0};
    for(int i=0; i<4; i++)
        cin >> s[i];

    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(s[i]==s[j] && mask[j]==0)
            {
                rep++;
                mask[j] = 1;
            }
        }
    }

    cout << rep << endl;

    return 0;
}