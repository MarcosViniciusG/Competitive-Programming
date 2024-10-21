#include <bits/stdc++.h>

using namespace std;

const int N_LETTERS = 26;

vector<char> oddLetters(string s)
{
    int counters[N_LETTERS] = {0};

    for(auto c: s)
        counters[c - 'a']++;

    vector<char> odds;
    for(int i=0; i< N_LETTERS; i++)
    {
        if(counters[i] % 2 != 0)
            odds.push_back(char('a' + i));
    }

    return odds;
}

int main()
{
    string s;
    getline(cin, s);

    vector<char> odds = oddLetters(s);
    if(odds.size()==1 || odds.size()==0 || odds.size() % 2!=0)
        cout << "First";
    else
        cout << "Second";

    cout << endl;

    return 0;
}