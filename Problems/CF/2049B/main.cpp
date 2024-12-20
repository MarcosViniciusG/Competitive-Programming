#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int l=0;
        int r=n-1;
        
        bool can=true;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c=='p') {
                r = i;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c=='s') 
                l = i;
        }

        if(l > r) {
            can = false;
        }
        else if(l!=0) {
            int l_sh = (r-l+1);
            int ls = (n-l);
            if(ls > l_sh)
                can = false;
        }
        
        cout << (can ? "YES" : "NO") << '\n';
    }

    return 0;
}