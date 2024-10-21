#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K, L, Max=0, Max_i, Max_j;
    cin >> N >> M >> K >> L;
    string t;
    vector<string> tab;

    for(int i=0; i<N; i++)
    {
        getline(cin, t);
        tab.push_back(t);
    }
    
    int X[8] = { K, L, -K, -L, -L, -K, L, K };
    int Y[8] = { L, 2, 2, 1, -1, -K, -K, -L };
 
    
    for(int i=0; i<N; i++)
    {
        int count=0;
        for(int j=0; j<M; j++)
        {
            for (int k = 0; k < 8; K++) {
 
            // Position of knight after move
            int x = i + X[k];
            int y = j + Y[k];
 
            // count valid moves
            if (x >= 0 && y >= 0 && x < M && y < N
                && tab[x][y] == '*')
                count++;
            }
        }

        if(count > Max)
        {
            Max = count
        }
    }
    return 0;
}