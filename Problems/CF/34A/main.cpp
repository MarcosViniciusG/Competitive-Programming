#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a, diff, min, s1, s2;
    vector<int> soldados; 
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        soldados.push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        diff = abs(soldados[i] - soldados[i-1]);

        if(i==1 || diff < min)
        {
            min = diff;
            s1 = i-1;
            s2 = i;
        }
    }

    if(abs(soldados[n-1]-soldados[0]) < min)
    {
        s1 = 0;
        s2 = n-1;
    }

    cout << (s1+1) << " " << (s2+1) << endl;
    return 0;
}