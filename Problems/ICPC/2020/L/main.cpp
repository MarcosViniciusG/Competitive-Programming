#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    int l, c;
    cin >> l >> c;

    vector<pair<int,int>> moves {(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)};

    vector<string> field(l);
    for(auto& p : field) cin >> p;

    int n;
    cin >> n;

    vector<vector<int>> grid(n);

    while(n--)
    {
        string s;
        cin >> s;

        map<char, int> hist;
        for(auto p : s) hist[p]++;

        for(int i = 0; i < l; i++)
        {
            auto it = field[i].find(s[0]);
            int savex = it - field[i].begin();
            int savey = i; 

            for(int j = 0; j < moves.size(); j++)
            {
                int x = savex, y = savey;
                map<char, int> comp;

                while(true)
                {
                    comp[field[x][y]]++;

                    int mx = moves[j].first;
                    int my = moves[j].second;

                    if(x+mx >= 0 && x+mx < c && y+my >= 0 && y+my < l)
                    {
                        x+=mx;
                        y+=my;
                    }

                    if(comp == hist)
                    {

                    }
                }
            }
        }
    }

    return 0;
}