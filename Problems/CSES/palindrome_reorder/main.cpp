#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    string s, palindrome="";
    cin >> s;
    bool impar1 = (s.size() % 2==0);

    map<char, int> counters;
    for(auto c: s)
    {
        if(counters.find(c)==counters.end())
            counters[c] = 1;
        else
            counters[c]++;
    }

    for(auto par: counters)
    {

    }

    cout << palindrome << endl;
    return 0;
}