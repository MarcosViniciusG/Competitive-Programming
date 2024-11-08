#include <bits/stdc++.h>
const int N_CHARS = 256;

using namespace std;
int main()
{
    bool can = true;
    char counters[N_CHARS] = {0};
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    for(auto c: s1) {
        if(c != ' ')
            counters[c]++;
    }

    for(auto c: s2)
    {
        if(counters[c])
            counters[c]--;
        else if(c != ' ')
        {
            can = false;
            break;
        }
    }

    if(can)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}