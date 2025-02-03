#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

ll desired;
   
signed main() {
    //cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string s;

    cin >> n;
    cin >> s;
    vector<pair<char, int>> graph[n+1];
    ll p3[n+1];
    p3[0] = 1;
    for(ll i=1; i<=n; i++)
        p3[i] = p3[i-1]*3;

    for(auto c: s) {
        graph[n].push_back({c, 0});
    }

    for(ll i=n; i>0; i--) {
        for(ll j=0; j<p3[i]; j+=3) {
            ll ones = (graph[i][j]==make_pair('1', 0)) + (graph[i][j+1]==make_pair('1', 0)) + (graph[i][j+2]==make_pair('1', 0));
            if(ones >= 2)
                graph[i-1].push_back({'1', 0});
            else
                graph[i-1].push_back({'0', 0});
        }
    }

    desired = !(graph[0][0].first - '0'); 
    set<ll> process;

    for(ll i=n; i>0; i--) {
        for(ll j=0; j<p3[i]; j+=3) {
            ll ones = (graph[i][j].first=='1') + (graph[i][j+1].first=='1') + (graph[i][j+2].first=='1');
            if(desired) {
                if(ones >= 2)
                    graph[i-1][j/3].second = 0;
                else
                    graph[i-1][j/3].second = 2 - ones;
            }
            else {
                if(ones < 2)
                    graph[i-1][j/3].second = 0;
                else
                    graph[i-1][j/3].second = ones;
            }
        }
    }


    return 0;
}