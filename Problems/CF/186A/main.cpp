#include <bits/stdc++.h>

using namespace std;
int main()
{
    bool can = true;
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    if(s1.size() != s2.size())
        can = false;

    int counters1[256] = {0};
    int counters2[256] = {0};
    for(int i=0; i<s2.size() && can; i++)
    {
        counters1[s1[i]]++;
        counters2[s2[i]]++;
    }

    for(int i=0; i<256 && can; i++)
    {
        if(counters1[i] != counters2[i])
            can = false;
    }

    int out=0;
    for(int i=0; i<s1.size() && can; i++)
    {
        if(s1[i] != s2[i])
            out++;

        if(out > 2)
            can = false;
    }

    if(can)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}