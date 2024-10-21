#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T, P, Li;
    vector<int> L;

    cin >> N >> T >> P;

    int n=0;
    for(int i=0; i<N && n<P; i++) {
        cin >> Li;
        if(Li >= T)
            n++;
        else
            L.push_back(Li);
    }

    if(n >= P) {
        cout << 0 << endl;
        return 0;
    }

    sort(L.begin(), L.end(), greater<int>());

    int nP = P - n;
    cout << T - L[nP-1] << endl;

    return 0;
}