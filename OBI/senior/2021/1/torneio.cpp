#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c=0;

    for(int i=0; i<6; i++)
    {
        char E;
        scanf(" %c", &E);
        if(E=='V') c++;
    }

    if(c>=5)
        cout << 1 << endl;
    else if(c>=3)
        cout << 2 << endl;
    else if(c >= 1)
        cout << 3 << endl;
    else
        cout << -1 << endl;

    return 0;
}