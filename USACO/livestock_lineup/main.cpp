#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    cin.ignore(1, '\n');
    
    string in;
    map<string, queue<string>> mp;
    set<string> names = {"Beatrice", "Bessie", "Buttercup", "Belinda", "Bella", "Blue", "Betsy","Sue"};
    
    vector<string> prob = {"must", "be", "milked", "beside"};
    map<string, bool> added;

    for(auto name: names)
    {
        cout << name << endl;
        mp[name] = {};
        added[name] = false;
    }

    while(N--)
    {
        getline(cin, in);
        string word="", primeira="";
        bool first=true;
        for(int i=0; in[i] !='\0'; i++)
        {

            char c=in[i];
            if(c!=' ' && in[i+1] !='\0')

                word+=c;
            else
            {
                if(in[i+1] =='\0') word+=c;

                bool diff=true;
                for(auto w: prob)
                    if(word==w) diff=false;

                if(diff)
                {
                    if(first)
                        primeira = word;
                    else
                    {
                        mp[primeira].push(word);
                        mp[word].push(primeira);
                    }

                    first = false;
                }

                word="";
            }
        }
            // cout << primeira << ": " << mp[primeira].front() << endl;
    }

    vector<string> order;
    for(auto name : names)
    {
        if(!added[name] && mp[name].size() <= 1)
        {
            added[name] = true;
            order.push_back(name);

            
        }
    }

}