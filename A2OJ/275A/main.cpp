#include <bits/stdc++.h>

using namespace std;

void toggle(int game[3][3], int y, int x)
{
    for(int i=-1; i<2; i++)
    {
        if((y+i)>=0 && (y+i)<3)
        {
            if(game[y+i][x]) game[y+i][x] = 0;
            else game[y+i][x] = 1;
        } 
    }

    for(int i=-1; i<2; i+=2)
    {
        if((x+i)>=0 && (x+i)<3)
        {
            if(game[y][x+i]) game[y][x+i] = 0;
            else game[y][x+i] = 1;
        } 
    }
}

int main()
{
    int game[3][3], times;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            game[i][j] = 1;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> times;
            bool even = (times % 2 == 0);
            if (!even) toggle(game, i, j);
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << game[i][j];
        }

        cout << endl;
    }

    return 0;
}