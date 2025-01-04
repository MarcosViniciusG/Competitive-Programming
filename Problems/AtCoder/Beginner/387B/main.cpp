#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x;
    cin >> x;

    int soma=0;
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            if(i*j != x)
                soma += i*j;
        }
    }

    cout << soma << '\n';
    return 0;
}