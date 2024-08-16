#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    bool sEven = (Sx + Sy)%2==0;
    bool tEven = (Tx + Ty)%2==0;

    ll distx = abs(Tx - Sx);
    ll disty = abs(Ty - Sy);

    cout << sEven << " " << tEven << endl;
    cout << distx << " " << disty << endl;

    //cout << min(disty, )
}