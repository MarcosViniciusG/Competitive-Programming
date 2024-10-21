#include <bits/stdc++.h>

using namespace std;
string str;

int main()
{
    cin >> str;
    set<string> perms;
    sort(str.begin(), str.end());

    do 
    {
        perms.insert(str);

    } while(next_permutation(str.begin(), str.end()));

    auto ptr = perms.begin();
    cout << perms.size() << endl;
    while(ptr!=perms.end())
    {
        cout << *ptr << endl;
        ptr++;
    }

    return 0;
}