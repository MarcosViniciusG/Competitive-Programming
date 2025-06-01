#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ll n;
    cin >> n;

    string isolado, normal;
    cin >> isolado >> normal;

    double total=0;
    double col = 0;
    for(int i=0; i<n; i++) {
        if(isolado[i]=='*') {
            total++;
            if(normal[i]!='*')
                col++;
        }
    }

    cout << fixed << setprecision(2) << col / total << '\n';
}