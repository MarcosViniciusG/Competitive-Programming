#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, i;
    cin >> n >> i;

    if(n & (1 << (i)))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}