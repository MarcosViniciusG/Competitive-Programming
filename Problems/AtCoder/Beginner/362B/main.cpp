#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int xab = abs(xa-xb);
    int yab = abs(ya-yb);

    int xac = abs(xa-xc);
    int yac = abs(ya-yc);

    int xbc = abs(xb-xc);
    int ybc = abs(yb - yc);

    int distab = (xab*xab + yab*yab);
    int distac = (xac*xac + yac*yac);
    int distbc = (xbc*xbc + ybc*ybc);

    int maxdist = max(distab, max(distac, distbc));

    int h;
    int c1;
    int c2;
    if(maxdist==distab) {
        h = distab;
        c1 = distac;
        c2 = distbc;
    }
    else if(maxdist==distac) {
        h = distac;
        c1 = distab;
        c2 = distbc;
    } 
    else if (maxdist==distbc) {
        h = distbc;
        c1 = distab;
        c2 = distac;
    }

    if(h == c1 + c2)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}