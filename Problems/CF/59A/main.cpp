#include <bits/stdc++.h>

using namespace std;
int main()
{
    int up=0;
    string word;
    cin >> word;
    for(auto c: word)
    {
        if(isupper(c)) up++;
    }

    if(up > (word.length() / 2)) 
    {
        for(int i=0; i<word.length(); i++)
        {
            word[i] = toupper(word[i]);
        }
    }
    else
    {
        for(int i=0; i<word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
    }

    cout << word << endl;

    return 0;
}