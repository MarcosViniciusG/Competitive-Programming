#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> n >> m;

    vector<string> grid1, grid2;
    cin.ignore(1, '\n');
    string s;
    for(int i=0; i<n; i++) {
        getline(cin, s);
        grid1.push_back(s);
    }

    for(int i=0; i<m; i++) {
        getline(cin, s);
        grid2.push_back(s);
    }

    int a=-1, b=-1;
    for(int i=0; i<n && a==-1; i++) {
        for(int j=0; j<n && b==-1; j++) {
            if(grid1[i][j]==grid2[0][0]) {
                bool is=true;
                int k, w, row, col;
                for(k=i, row=0; row<m && k<n && is; row++, k++) {
                    for(w=j, col=0; col<m && w<n && is; col++, w++) {
                        if(grid1[k][w]!=grid2[row][col]) 
                            is=false;
                    }
                }

                if(is && row==m && col==m) {
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a+1 << ' ' << b+1 << '\n';

    return 0;
}