#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 0, low = 0, up = 0, sumup=0, sumlow=0;
    cin >> n;
    vector<pair<int,int>> domino(n);

    for (int i = 0; i < n; i++)
    {
        cin >> domino[i].first >> domino[i].second;
        sumup += domino[i].first;
        sumlow += domino[i].second;
    }

    bool hasChangeable=false;
    for (int i = 0; i < n; i++)
    {
        if(domino[i].first % 2) { 
            up++;
            if(domino[i].second % 2==0)
                hasChangeable = true;
        };
        if(domino[i].second % 2) {
            low++;
            if(domino[i].first % 2==0)
                hasChangeable = true;
        }
    }

    if((sumup % 2==0) && (sumlow % 2==0)) cout << 0 << endl;
    else if(((up+low) % 2) || (!hasChangeable && ((sumup%2) || (sumlow%2)))) cout << -1 << endl;
    else cout << 1 << endl;

    return 0;
}