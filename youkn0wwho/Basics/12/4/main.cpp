#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int m = max(A, B);
    int mi = min(A, B);

    int ans = 0;
    if(m-mi >= 2)
        ans = m + (m-1);
    else
        ans = m + mi;

    cout << ans << endl;
    return 0;
}