#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k, a;
    cin >> n >> k;

    vector<int> as;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        as.push_back(a);
    }

    bool can = true;
    for(int i=k; i<n && can; i++)
    {
        if(as[k-1] != as[i])
            can = false;
    }

    int moves=0;
    for(int i=0; i<k && can; i++)
    {
        if(as[k-1] != as[i])
            moves = i+1;
    }

    if(!can)
        moves = -1;

    cout << moves << endl;

    return 0;
}