#include <bits/stdc++.h>

using namespace std;
int main()
{
    int V, N;

    cin >> N >> V;

    int S[N];

    for(int i=0; i<N; i++)
    {
        cin >> S[i];
    }

    int coins=0;
    for(int i=N-1; i>=0; i--)
    {
        while(V>=S[i])
        {
            coins++;
            V -= S[i];
        }
    }

    cout << coins << endl;

    return 0;
}