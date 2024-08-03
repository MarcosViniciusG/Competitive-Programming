#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<char> naipes ({'C', 'E', 'U', 'P'});
    map<char, set<string>> mp;
    map<char, bool> err;

    for(auto n: naipes)
    {
        mp[n] = {};
        err[n] = false;
    }

    string str;
    string dd;
    cin >> str;
    for(int i=2; i<str.length(); i+=3)
    {
        dd = "";
        dd += str[i-2];
        dd += str[i-1];
        auto ret = mp[str[i]].insert(dd);
        if (!ret.second)
            err[str[i]] = true;
    }

    for(auto e: naipes)
    {
        if(err[e])
        {
            cout << "erro" << endl;
            continue;
        }
        else
        {
            cout << 13 - mp[e].size() << endl;
        }
    }

    return 0;
}