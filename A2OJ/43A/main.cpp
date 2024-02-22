#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    string s;
    cin >> n;
    map<string, int> mp;

    while(n--)
    {
        cin.ignore(1, '\n');
        cin >> s;

        if(mp.find(s)==mp.end()) 
            mp[s]=1;
        else
            mp[s]++;
    }

    int maior=0;
    string time;
    for(auto par: mp)
    {
        if(par.second > maior)
        {
            maior = par.second;
            time = par.first;
        }
    }

    cout << time << endl;
}