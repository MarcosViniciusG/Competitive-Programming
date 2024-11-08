#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    getline(cin, s);
    
    int mask[s.size()] = {0};

    int zero = -1;
    for(int i=0; i<s.size(); i++)
    {
        
        if(s[i]=='0') {
            zero = i;
            break;
        }
    }

    if(zero!=-1)
        mask[zero] = 1;
    else
        mask[0] = 1;


    for(int i=0; i<s.size(); i++)
    {
        if(!mask[i])
            cout << s[i];
    }

    cout << endl;

    return 0;
}