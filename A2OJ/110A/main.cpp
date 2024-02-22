#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll count=0;
    bool nearly = true;
    string n;
    cin >> n;
    for(auto d: n)
    {
        if(d=='4' || d=='7') count++;
    }

    string count_s = to_string(count);

    for(auto d: count_s)
    {
        if(d!='4' && d!='7')
        {
            nearly = false;
            break;
        }
    }

    if(nearly) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}