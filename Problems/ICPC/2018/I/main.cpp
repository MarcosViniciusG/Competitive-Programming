#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, l, m;
    cin >> n >> m;
    bool a[m];
    memset(a, 0, sizeof(a));
    cin >> l;
    int li;
    for(int i=0; i<l; i++) {
        cin >> li;
        li--;
        a[li] = 1;
    }

    vector<vector<int>> v;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        cin >> l;
        int mi;
        for(int i=0; i<l; i++) {
            cin >> mi;
            mi--;
            temp.push_back(mi);
        }
        v.push_back(temp);
    }

    int ans=1;
    for(int i=0; i<n; i++) {
        for(auto e: v[i]) {
            a[e] = !a[e];  
        }

        bool on = false;
        for(int j=0; j<m; j++) {
            if(a[j])    
                on = true; 
        }

        if(on) {
            ans++;
        }
        else
            break;
    }

    if(ans > n) {
        for(int i=0; i<n; i++) {
            for(auto e: v[i]) {
                a[e] = !a[e];  
            }

            bool on = false;
            for(int j=0; j<m; j++) {
                if(a[j])    
                    on = true; 
            }

            if(on) {
                ans++;
            }
            else
                break;
        }    
    }
    if(ans > 2*n)
        ans=-1;

    cout << ans << '\n';

}