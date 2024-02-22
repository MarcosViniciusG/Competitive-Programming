#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n=10;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int l=-1, r=n;
    int k;
    cin >> k;
    while (r-l>1)
    {
        int m = (l+r) / 2;
        if(k < a[m]) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << l << endl;
    

    return 0;
}