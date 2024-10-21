#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(ll current, ll n) {
    if(current > n)
        return false;
    else if(current==n)
        return true;
    else {
        bool c1 = solve(current*10, n);
        bool c2 = solve(current*20, n);
        return (c1 || c2);
    }
}

int main() {
    int T;
    cin >> T;

    ll n;
    while(T--) {
        cin >> n;
        bool can = solve(1, n);
        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


}