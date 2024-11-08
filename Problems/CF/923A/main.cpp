#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t, n, minimum, prev;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin.ignore(1, '\n');
        cin >> s;
        
        prev = -1;
        minimum=0;

        for(int i=0; i<n; i++)
        {
            if(prev==-1 && s[i]=='B')
            {
                minimum = 1;
                prev = i;
            }
            else if(s[i]=='B')
            {
                minimum += i - prev;
                prev = i;
            } 
        }

        cout << minimum << endl;
    }
}