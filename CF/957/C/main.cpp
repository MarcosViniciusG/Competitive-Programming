#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, k;

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        vector<int> perm;

        for(int i=n; i>=k; i--)
            perm.push_back(i);
        
        for(int i=k-1; i>m; i--)
            perm.push_back(i);

        for(int i=1; i<=m; i++)
            perm.push_back(i);

        for(auto e: perm)
            cout << e << " ";
        cout << endl;
    }
}