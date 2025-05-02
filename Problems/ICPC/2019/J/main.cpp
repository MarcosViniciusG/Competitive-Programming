#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<string> cards(n);
    for(auto& p : cards) cin >> p;

    vector<bool> joker(n, false);
    for(int i = k-1; i <= n; i++)
    {
        i %= n;


    }
}