#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a;
    cin >> n;

    int counters[7] = {0};
    int solutions[n/3][3];

    bool can = true;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a==7)
            can = false;
        else
            counters[a] += 1;
    }

    for(int i=0; i<(n/3) && can; i++) {
        int c = 0;
        for(int j=1; j < 7 && c<3; j++) {
            if(counters[j]==0)
                continue;

            if(c==0 || (j % solutions[i][c-1]==0))
            {
                solutions[i][c] = j;
                c++;
                counters[j]--;
            }    
        }
        if(c < 3)
            can = false;
    }

    if(!can)
        cout << -1 << endl;
    else
    {
        for(int i=0; i<(n/3); i++) {
            for(int j=0; j < 3; j++) {
                cout << solutions[i][j] << " ";
            }
        cout << endl;
        }
    }

    return 0;
}