#include <bits/stdc++.h>

using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if(((A*A) + (B*B)) < (C*C))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}