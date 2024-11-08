#include <bits/stdc++.h>

using namespace std;

void solve(int n, int x, int y)
{
    int ans[n];
    ans[i] = 1;
    int sum = 1; 

    bool alt = true;
    for(int i=0; i<n; i++)
    {
        if(i+1 < y)
        {
            if(alt)
            {
                ans[i] = -1;
                alt = false;
            }
            else
            {
                ans[i] = 1;
                alt = true;
            }
        }


        if(i+1 > x)
        {

        }

        sum += ans[i];
    }

    for(int i=0; i<n; i++)
    {
        cout << ans[i] << " ";   
    }
    cout << endl;
}

int main()
{
    int t, n, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y;
    }

    return 0;
}