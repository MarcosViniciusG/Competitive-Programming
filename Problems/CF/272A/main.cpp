#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a, soma=0, solution=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        soma += a;
    }

    for(int i=1; i<=5; i++)
    {
        if((soma+i) % (n+1) != 1) solution++;
    }

    cout << solution << endl;
    return 0;
}