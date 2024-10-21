#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;
    bool dangerous = false;
    int count = 0;
    char prev=s[0];

    for(auto c: s)
    {
        if(c==prev)
            count++;
        else
        {
            prev = c;
            count = 1;
        }

        if(count==7)
        {
            dangerous = true;
            break;
        }
    }

    if (dangerous)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}