#include <bits/stdc++.h>

using namespace std;

string s, per;
vector<string> perms;
int char_count[26] = {0};

void search()
{
    if(s.size()==per.size())
    {
        perms.push_back(per);
        return;
    }

    for(int i=0; i<26; i++)
    {
        if(char_count[i] > 0)
        {
            char_count[i]--;
            per += (char)('a'+i);

            search();

            char_count[i]++;
            per.pop_back();
        }
    }
}

int main()
{
    cin >> s;
    for(char c: s)
        char_count[c-'a']++;

    search();
    
    cout << perms.size() << endl;
    for(auto perm: perms)
        cout << perm << endl;

    return 0;
}