#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int i;
    string s, t;
    cin >> s;
    cin.ignore(1, '\n');
    cin >> t;
    for(i=0; s[i]!='\0' && t[i]!='\0' && s[i] == t[t.size() - i - 1] ; i++)
    {
        // cout << t[t.size()-i-1] << endl;
    }

    if(i==s.size())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}