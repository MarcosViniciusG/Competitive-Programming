#include <bits/stdc++.h>

using namespace std;
int main()
{
    int e, moves;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin >> e;
            if(e)
            {
                moves = abs(2-i) + abs(2-j);
            }
        }
    }

    cout << moves << endl;

    return 0;
}