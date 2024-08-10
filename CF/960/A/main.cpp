#include <bits/stdc++.h>

using namespace std;
bool isEven(int n) {
    return n % 2==0;
}

bool solve(int n, vector<int> as)
{
    sort(as.begin(), as.end());
    int big = as[n-1];

    int C[n+1] = {0};
    for(int i=n-1; i>=0; i--)
        C[as[i]]++;

    int oddN=0;
    for(int i=1; i<=n && oddN < 1; i++)
        if(!isEven(C[i])) 
            oddN++;

    return (!isEven(C[big]) || oddN >= 1);
}

int main()
{
    int t, n, a;
    cin >> t;
    while(t--)
    {
        vector<int> as;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a;
            as.push_back(a);
        }
        bool can = solve(n, as);
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}