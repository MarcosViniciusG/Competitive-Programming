#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        bool change = true;
        while (change)
        {
            change = false;
            ll n = s.length();
            for(int i=0; i<n-1; i++) {
                if(s[i]==s[i+1]) {
                    if(i!=0) 
                        s[i] = s[i-1];
                    else if(i+2 < n)
                        s[i] = s[i+2];
                    
                    s.erase(i+1);
                    change = true;
                    break;
                }
                
            }
        }
        
        cout << s.length() << '\n';
    }
    

    return 0;
}