#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ai;
    cin >> n;

    vector <int> a;
    for(int i=0; i<n; i++) {
        cin >> ai;
        a.push_back(ai);
    }

    bool c = false;
    for(int bit=0; bit<(1 << n) && (!c); bit++) {
        int sum = 0;

        for(int j=0; j<n; j++) {
            if((bit & (1 << j)) != 0)
                sum += a[j];
            else
                sum -= a[j];
        }

        c = (sum % 360==0);
    }

    if(c)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}