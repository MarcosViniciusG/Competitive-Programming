#include <bits/stdc++.h>

using namespace std;
int main()
{
    string nome;
    set<char> distinct;
    cin >> nome;

    for(auto c: nome) distinct.insert(c);

    if(distinct.size() % 2==0) cout << "CHAT WITH HER!\n";
    else cout << "IGNORE HIM!\n";
    return 0;
}