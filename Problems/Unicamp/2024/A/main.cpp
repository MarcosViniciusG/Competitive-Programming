#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    ll t;
    cin >> t;

    while (t--) 
    {
        bool ans = true;
        int n, m;
        cin >> n >> m;

        map<int, int> m1, m2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int num;
                cin >> num;
                m1[num]++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int num;
                cin >> num;
                m2[num]++;
            }
        }

        if(m1 != m2) ans = false;
        
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}