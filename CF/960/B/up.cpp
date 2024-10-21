#include <bits/stdc++.h>

using namespace std;

void solve(int n, int x, int y)
{
    x--;
    y--;
    int a[n];
    bool alt = false;
    for(int i=y-1; i>=0; i--) {
        if(alt) {
            a[i] = 1;
            alt = false;
        }

        else {
            a[i] = -1;
            alt = true;
        }
    }

    alt = false;
    for(int i=x+1; i<n; i++) {
        if(alt) {
            a[i] = 1;
            alt = false;
        }

        else {
            a[i] = -1;
            alt = true;
        }
    }

    alt = false;
    for(int i=y; i<=x; i++) 
        a[i] = 1;

    for(int i=0; i<n; i++) 
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        solve(n, x, y);
    }
    
    return 0;
}