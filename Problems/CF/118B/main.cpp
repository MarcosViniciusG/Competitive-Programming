#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int spaces = n;

    for(int i=0; i<=n; i++)
    {
        for(int i=0; i<spaces; i++)
            cout << "  ";

        for(int j=0; j<=i; j++)
        {
            cout << j;
            if(j!=i)
                cout << ' ';
        }
        

        for(int j=i-1; j>=0; j--)
        {
            if(j==i-1)
                cout << ' ';

            cout << j;
            if(j!=0)
                cout << ' ';
        }

        cout << endl;
        spaces--;
    }

    spaces+=2;
    for(int i=n-1; i>=0; i--)
    {
        for(int i=0; i<spaces; i++)
            cout << "  ";

        for(int j=0; j<=i; j++)
        {
            cout << j;
            if(j!=i)
                cout << ' ';

        }

        for(int j=i-1; j>=0; j--)
        {
            if(j==i-1)
                cout << ' ';

            cout << j;
            if(j!=0)
                cout << ' ';
        }

        cout << endl;
        spaces++;
    }

    return 0;
}