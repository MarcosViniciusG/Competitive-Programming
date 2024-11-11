#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string s;
        cin.ignore(1, '\n');
        getline(cin, s);

        bool found=false;
        int x=0, y=0;
        while(!found) {
            int prev_x=x;
            int prev_y=y;

            for(int i=0; i<n; i++) {
                if(s[i]=='N')
                    y++;
                else if (s[i]=='E')
                    x++;
                else if (s[i]=='S')
                    y--;
                else if (s[i]=='W')
                    x--;
                
                if(x==a && y==b) {
                    found = true;
                    break;
                }
            }

            if(found)
                break;

            if(x==prev_x && y==prev_y) 
                break;

            if(x>=100 || y>=100) {
                break;
            }
            if(x<=-100 || y<=-100) {
                break;
            }      
        }

        if(found)
            cout << "YES\n";
        else    
            cout << "NO\n";
    }
    

    return 0;
}