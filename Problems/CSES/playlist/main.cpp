#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> x;
    int xi;
    for(int i=0; i<n; i++) {
        cin >> xi;
        x.push_back(xi);
    }

    set<int> mus;
    int l=0;
    int ans=1;
    for(int r=0; r<n; r++) {
        if(mus.find(x[r])==mus.end())
            mus.insert(x[r]);
        else {
            while(x[l]!=x[r]) {
                mus.erase(x[l]);
                l++;
            } 
            mus.erase(x[l]);
            l++;
            mus.insert(x[r]);
        }

        ans = max(ans, int(mus.size()));
    }

    cout << ans << "\n";

    return 0;
}