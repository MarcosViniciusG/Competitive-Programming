#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, li, ri;
    cin >> n >> m;
    
    // For every r in [1, m], there is a number
    // dr that every pair of integers in (dr, r)
    // satisfies the condition

    vector<int> d(m+1, 1);
    for(int i=0; i<n; i++) {
        cin >> li >> ri;
        d[ri] = max(d[ri], li+1);
    }

    for(int i=1; i<=m; i++) {
        d[i] = max(d[i], d[i-1]);
    }

    long long soma=0;
    for(int i=1; i<=m; i++)
        soma += (i - d[i]+1);

    cout << soma << '\n';
    return 0;
}