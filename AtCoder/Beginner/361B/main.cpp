#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;

    bool can = true;
    if((g >= d || j <= a) || (h >= e || k <= b) || (i >= f || l <= c))
        can = false; 

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}