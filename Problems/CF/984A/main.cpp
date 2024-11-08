#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a (n);
        for(int &i: a) 
            cin >> i;
        
        bool is=true;
        for(int i=1; i<n; i++) {
            if ((abs(a[i]-a[i-1])!=5) && 
            (abs(a[i]-a[i-1])!=7))
                is = false;
        }

        if(is)
            cout << "YES\n";
        else
            cout << "NO\n";
    }    

    return 0;
}