#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n, m;
    string s;

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin.ignore(1, '\n');
        
        int x=0;
        bool f = true;
        for(int i=0; i<n; i++) {
            getline(cin, s);
            if((m - s.length() >= 0) && f) {
                m -= s.length();
                x++;
            }
            else
                f = false;
        }

        cout << x << '\n';
    }

    return 0;
}