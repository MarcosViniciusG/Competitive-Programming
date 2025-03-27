#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, R, C;
    cin >> N >> R >> C;
    
    string S;
    cin >> S;
    
    map<char, pair<int,int>> mp;
    mp['N'] = {-1, 0};
    mp['W'] = {0, -1};
    mp['S'] = {1, 0};
    mp['E'] = {0, 1};
    
    set<pair<int, int>> pos;
    int deltax=0;
    int deltay=0;
    pos.insert({0, 0});
    string ans="";
    for(auto c: S) {
        deltay += -mp[c].first;
        deltax += -mp[c].second;
        
        R += -mp[c].first;
        C += -mp[c].second;
        
        pos.insert({deltay, deltax});
        if(pos.find({R, C})!=pos.end())
            ans += '1';
        else
            ans += '0';
    }
    
    cout << ans << '\n';

    return 0;
}