#include <bits/stdc++.h>

using namespace std;
#define int long long
map<int, char> mp1;
map<char, int> mp2;

bool comp (const pair<double, string> a, const pair<double,string> b) {
    if(fabs(a.first - b.first) < 0.0000001f && a.second < b.second) return true;
    if(a.first > b.first) return true;
    return false;
}

vector<pair<int, int>> graph;
pair<double, string> dp[13][1 << 13];

int n, m;

double dist(pair<int, int> c1, pair<int, int> c2) {
    int x = c2.first - c1.first;
    int y = c2.second - c1.second;
    return sqrt(x*x + y*y);
}

pair<double, string> solve(string ans, int visited, int k, double d) {
    int last_visited = 0;
    int sede = 0;
    if(!ans.empty()) {
        last_visited = mp2[ans[k-1]];
        sede = mp2[ans[0]];
    }

    if(k==m) {
        double res = d + dist(graph[last_visited], graph[sede]);
        return dp[last_visited][visited] = {-res, ans};
    }

    pair<double, string> temp_ans = {double(-INT_MAX), ""};
    for(int i=0; i<n; i++) {
        if(!(visited & (1 << i))) {
            // mark node i as visited
            int n_visited = visited | (1 << i);
            ans += mp1[i];

            double distance = d;
            if(k>0)
                distance += dist(graph[last_visited], graph[i+1]);
            
            pair<double, string> temp = solve(ans, n_visited, k+1, distance);
            bool compared = (!comp(temp_ans, temp));
            
            if(compared) {
                temp_ans = temp;
            }

            // mark node i as unvisited
            ans.pop_back();
        }
    }

    return dp[last_visited][visited] = temp_ans;
}

signed main() {
    cin >> n >> m;

    // mapping
    for(int i=0; i<10; i++) {
        mp1[i] = i + '0' + 1;
        mp2[i + '0' + 1] = i+1;
    }
    mp1[10] = '#';
    mp1[11] = ';';
    mp1[12] = '.';

    mp2['#'] = 11;
    mp2[';'] = 12;
    mp2['.'] = 13;
    // end mapping

    for(int i=0; i<13; i++)
    for(int j=0; j<(1<<13); j++)
        dp[i][j] = {-1, "-1"};

    int xi, yi;
    graph.push_back({0, 0});
    for(int i=0; i<n; i++) {
        cin >> xi >> yi;
        graph.push_back({xi, yi});
    }

    solve("", 0 , 0, 0);
    
    // for(int i=0; i<n; i++) {
    // for(int j=0; j<(1<<n); j++)
    //     cout << dp[i][j].first << ": " << dp[i][j].second << ' ';
    //     cout << '\n';
    // }

    cout << fixed << setprecision(8) << -dp[0][0].first << '\n';
    for(int i=0; i<m; i++) {
        cout << mp2[dp[0][0].second[i]] << ' ';
    }
    cout << "\n";

    return 0;
}