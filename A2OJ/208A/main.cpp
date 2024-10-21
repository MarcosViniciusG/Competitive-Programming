#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i;
    string s, solution="";
    cin >> s;

    for(i=0; i < s.size(); i++)
    {
        if(s[i]=='W' && i+1 < s.size() && s[i+1]=='U' && i+2 < s.size() && s[i+2] == 'B')
            i+=2;
        else break;
    }

    for(i=i; i < s.size(); i++)
    {
        if(s[i]=='W' && i+1 < s.size() && s[i+1]=='U' && i+2 < s.size() && s[i+2] == 'B')
            break;
        else
            solution += s[i];
    }

    bool debounce = false;

    for(i=i; i < s.size(); i++)
    {
        if(s[i]=='W' && i+1 < s.size() && s[i+1]=='U' && i+2 < s.size() && s[i+2] == 'B')
        {
            i+=2;
            debounce = false;
        }
        else
        {
            if(!debounce)
            {
                solution += " ";
                debounce = true;
            }

            solution += s[i];
        }
    }

    cout << solution << endl;
}