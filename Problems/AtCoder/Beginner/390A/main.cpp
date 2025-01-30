#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int A[5];
    bool s=false;
    for(int i=0; i<5; i++) {
        cin >> A[i];
        if(i!=0 && A[i-1] > A[i] && !s) {
            swap(A[i-1], A[i]);
            s=true;
        }
        else if(A[i-1] > A[i] && s) {
            cout << "No\n";
            return 0;
        }
    }

    if(s)
        cout << "Yes"  << '\n';
    else
        cout << "No\n";
    return 0;
}