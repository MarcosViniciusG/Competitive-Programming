#include <bits/stdc++.h>

using namespace std;

int dir_y[] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dir_x[] = { 0, 1, 1, 1, 0,-1,-1,-1};

vector<string> ss;
int cc_sizes[100][100];

int floodfill(int i, int j, char c1, char c2, vector<pair<int, int>> &part) {
    if((i < 0) || (i==ss.size())) return 0;
    if((j < 0) || (j>=ss[0].size())) return 0;
    if(ss[i][j] != c1) return 0;
    
    int ans=1;
    ss[i][j] = c2;
    part.push_back(make_pair(i, j));

    for(int k=0; k<8; k++) {
        ans += floodfill(i+dir_y[k], j+dir_x[k], c1, c2, part);
    }

    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int cases;

    cin >> cases;
    cin.ignore(1, '\n');
    string s;
    getline(cin, s);
    while(cases--)
    {
        memset(cc_sizes, -1, sizeof(cc_sizes));
        do {
            getline(cin, s);
            if(s[0]=='L' || s[0]=='W')
                ss.push_back(s);
        } while(s[0]=='L' || s[0]=='W');

        vector<pair<int, int>> queries;
        while(!s.empty()) {
            queries.push_back(make_pair(s[0]-'0'-1, s[2]-'0'-1));
            getline(cin, s);
        }

        // for(auto str: ss) {
        //     for (auto c:str)
        //         cout << c;
            
        //     cout << '\n';
        // }

        // for(auto par: queries) 
        //     cout << par.first << ' ' << par.second << '\n';
        
        for(auto q: queries) {
            if(cc_sizes[q.first][q.second]==-1) {
                vector<pair<int, int>> part;
                int ans = floodfill(q.first, q.second, 'W', '.', part);
                for(auto par: part)
                    cc_sizes[par.first][par.second] = ans;
            }

            cout << cc_sizes[q.first][q.second] << '\n';
        }

        cout << '\n';
        ss.clear();
    }

    return 0;
}