#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, a, i, max_sum=0, min_sum=0;
    priority_queue<int, vector<int>> planes;
    priority_queue<int, vector<int>, greater<int>> pl;

    cin >> n >> m;
    
    for(i=0; i<m; i++)
    {
        cin >> a;
        planes.push(a);
        pl.push(a);
    }

    for(i=0; i<n; i++)
    {
        int last_plane = planes.top();
        max_sum += last_plane;
        planes.pop();
        last_plane--;
        if(last_plane > 0)
            planes.push(last_plane);
    }

    for(i=0; i<n; i++)
    {
        int last_plane = pl.top();
        min_sum += last_plane;
        pl.pop();
        last_plane--;
        if(last_plane > 0)
            pl.push(last_plane);
    }

    cout << max_sum << " " << min_sum << endl;
    return 0;
}