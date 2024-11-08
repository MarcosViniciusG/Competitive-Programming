#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

bool intersection(int l1, int r1, int l2, int r2) {
    return((l2 >= r1 || r2 <= l1));
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;

    bool can = true;
    if(intersection(a, d, g, j) || intersection(b, e, h, k) || intersection(c, f, i, l))
        can = false; 

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}