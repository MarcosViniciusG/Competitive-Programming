#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;

    map<char, int> counters;
    counters['h'] = 0;
    counters['e'] = 0;
    counters['l'] = 0;
    counters['o'] = 0;

    for(auto c: s)
    {
        if(c=='h')
            counters['h']++;
        
        if(c=='e' && counters['h']>0)
            counters['e']++;

        if(c=='l' && counters['e']>0)
            counters['l']++;
        
        if(c=='o' && counters['l']>1)
            counters['o']++;
    }

    if(counters['h'] > 0 && counters['e'] > 0 && counters['l'] > 1 && counters['o'] > 0)
        cout << "YES\n";
    else  
        cout << "NO\n";

    return 0;
}