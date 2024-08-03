#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, x, y, distance=0;
    vector<int> xs, ys;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        xs.push_back(x);
    }

    for(int i=0; i<n; i++)
    {
        cin >> y;
        ys.push_back(y);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int dx = xs[i] - xs[j];
            int dy = ys[i] - ys[j];

            int square = dx*dx + dy*dy;
            distance = max(distance, square);
        }
    }

    cout << distance << endl;

    return 0;  
}