#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s, ans="";
    cin >> s;
    for(auto c: s)
    {
        if(!(toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'Y' || toupper(c) == 'U'))
        {
            ans += '.';
            ans += tolower(c);
        }
    }

    cout << ans << endl;
    return 0;   
}