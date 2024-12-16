#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string p, h;
        cin >> p >> h;
        int n = h.length();
        int np = p.length();

        bool can = false;

        vector<int> hist1 (26, 0);
        for(auto c: p)
            hist1[c-'a']++;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                
                vector<int> hist2 (26, 0);
                for(int k=i; k<(n-j); k++) {
                    hist2[h[k]-'a']++;
                }

                if(hist1==hist2)
                    can = true;    
            }
        }

        cout << (can ? "YES" : "NO") << '\n';
    }

    return 0;
}