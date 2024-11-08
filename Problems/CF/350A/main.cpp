#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, ai, bi;
    cin >> n >> m;

    int maiorA=0, menorA=101;
    for(int i=0; i<n; i++) {
        cin >> ai;
        menorA = min(menorA, ai);
        maiorA = max(maiorA, ai);
    }

    int v = max(2*menorA, maiorA);

    bool can = true;
    for(int i=0; i<m; i++) {
        cin >> bi;
        if(bi <= v)
            can = false;
    }

    if(can)
        cout << v << endl;
    else
        cout << -1 << endl;
    return 0;
}