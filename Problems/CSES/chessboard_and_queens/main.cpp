#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int n=8;
ll counter = 0;
int board[n][n];
int column[n];
int diag1[2*n];
int diag2[2*n];

void search(int y)
{
    if(y==n)
    {
        counter++;
        return;
    }
    for(int x=0; x<n; x++)
    {
        if(column[x] || diag1[x+y] || diag2[x-y+n-1] || board[y][x]) continue;

        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main()
{
    char c;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> c;
            if(c=='*')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
        cin.ignore(1, '\n');
    }

    memset(column, 0, sizeof(column));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    search(0);

    cout << counter << endl;
    return 0;
}