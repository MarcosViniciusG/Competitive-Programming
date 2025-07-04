#include <bits/stdc++.h>

using namespace std;

signed main() {
    int l, h;
    cin >> l >> h;
    if(l & 1)
        cout << h << '\n';
    else
        if(h & 1)
            cout << h-1 << '\n';
        else
            cout << h << '\n';

}