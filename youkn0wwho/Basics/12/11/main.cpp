#include <bits/stdc++.h>

using namespace std;

int main() {
    double A, B;
    cin >> A >> B;
    double ans = (1 - (B/A)) * 100;
    cout << ans << endl;
    return 0;
}