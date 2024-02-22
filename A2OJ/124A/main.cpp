#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a, b, counter=0, pos=0;
    cin >> n >> a >> b;

    for(int i=1; i<=n; i++)
    {
        if(i!=1)
            counter++;

        // cout << counter << endl;
        // cout << n - i << endl;

        if((n-i) >= a && counter <= b)
        {
            pos++;
            // cout << counter << endl;
            // cout << n - i << endl;
        }
    }

    cout << pos << endl;
    return 0;
}