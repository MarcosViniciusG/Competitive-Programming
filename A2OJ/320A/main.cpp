#include <bits/stdc++.h>

using namespace std;
int main()
{
    string n;
    cin >> n;
    bool magic = true;
    for(long long i=0; i<n.size(); i++)
    {
        if(n[i]=='1')
        {
            if(i+1 < n.size() && n[i+1]=='4')
            {
                if(i+2 < n.size() && n[i+2]=='4')
                    i+=2;
                else
                    i++;
            }
        }
        else
            magic = false;
    }

    if(magic) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}