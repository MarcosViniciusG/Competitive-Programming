#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20;

int n;

void backtracking(int i, bool choosed[])
{
    if(i==n)
    {
        for(int j=0; j<n; j++)
        {
            if(choosed[j])
                cout << j << " ";
        }
        cout << endl;
        return;
    }

    choosed[i] = false;
    backtracking(i+1, choosed);

    choosed[i] = true;
    backtracking(i+1, choosed);
}

int main()
{
    bool choosed[MAXN];
    cin >> n;

    cout << "Todos os subconjuntos: " << endl;
    backtracking(0, choosed);
    return 0;
}