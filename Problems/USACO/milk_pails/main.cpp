#include <bits/stdc++.h>

using namespace std;
int main()
{
    int x, y, m, biggest=0, productx=0, producty=0;
    cin >> x >> y >> m;
    for(int i=0; productx < m; i++)
    {
        productx = i * x;
        producty = 0;
        for(int j=0; productx + producty < m; j++)
        {
            biggest = max(biggest, productx + producty);
            producty = j * y;
        }
    }

    cout << biggest << endl;

    return 0;
}