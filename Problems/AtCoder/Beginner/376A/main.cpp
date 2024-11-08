#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, c, t, count = 0, last;
    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if(!i || (t - last) >= c)
        {
            last = t;
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}