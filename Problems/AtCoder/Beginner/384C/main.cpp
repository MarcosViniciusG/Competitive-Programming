#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int points[5];
    char v[] = {'A', 'B', 'C', 'D', 'E'};
    for(int i=0; i<5; i++) {
        cin >> points[i];
    }

    vector<vector<string>> cont (14000);
    for(int bit=0; bit < (1 << 5); bit++) {
        string s="";
        int p=0;
        for(int i=0; i<5; i++) {
            if((1 << i) & bit) {
                s += v[i];
                p += points[i]; 
            }
        }
        if(!s.empty())
            cont[p].push_back(s);
    }

    for(int i=13999; i>=0; i--) {
        if(!cont[i].empty()) {
            sort(cont[i].begin(), cont[i].end());
            for(auto str: cont[i]) {
                cout << str << '\n';
            }
        }
    }

    return 0;
}