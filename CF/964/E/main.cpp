#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

const int MAXN = 200010;
int main() {
    int t, l, r;
    cin >> t;

    int lg[MAXN+1];
    lg[1] = 0;
    lg[2] = 0;
    for (int i = 3; i <= MAXN; i++)
        lg[i] = lg[i/3] + 1;

    int prefix[MAXN+1];
    prefix[1] = 2;
    for(int i=2; i<=MAXN; i++) {
        prefix[i] = lg[i] + 1 + prefix[i-1]; 
    }

    while(t--) {
        cin >> l >> r;
        int noi=0;
        if(l!= 1)
            noi = lg[l] + 1;

        int no = noi + (prefix[r] - prefix[l-1]);

        cout << no << endl;
    }

    return 0;
}