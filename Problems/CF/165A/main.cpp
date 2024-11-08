#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, x, y, count=0, i;
    map<pair<int, int>, vector<bool>> mp;
    
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x >> y;
        mp[make_pair(x, y)] = {0, 0, 0 ,0};
    }

    for(auto ponto1: mp)
    {
        auto coord1 = ponto1.first;
        //cout << coord1.first << " " << coord1.second << endl;
        for(auto ponto2: mp)
        {
            auto coord2 = ponto2.first;
            //cout << coord2.first << " " << coord2.second << endl;
    
            if(coord1.first==coord2.first && coord1.second==coord2.second) continue;

            if(coord1.first==coord2.first)
            {
                if(coord1.second > coord2.second) mp[coord1][0] = 1;
                else if(coord1.second < coord2.second) mp[coord1][1] = 1;
            }

            else if(coord1.second==coord2.second)
            {
                if(coord1.first > coord2.first) mp[coord1][2] = 1;
                else if(coord1.first < coord2.first) mp[coord1][3] = 1;
            }
        }
    }

    for(auto par: mp)
    {
        bool flag = true;
        for(i=0; i<4; i++)
        {
            if(par.second[i]==0) flag = false;
            //cout << par.second[i] << endl;
        }

        if (flag) count++;
    }

    cout << count << endl;
    return 0;
}