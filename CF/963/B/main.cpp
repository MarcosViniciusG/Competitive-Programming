#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

bool iseven(ll n) {
    return (n%2==0);
}

int main() {
    ll t, n, ai;
    cin >> t;
    while(t--) {
        ll no=0;

        cin >> n;
        vll odd;
        vll even;
        ll biggestodd=0;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            if(iseven(ai))
                even.push_back(ai);
            else {
                odd.push_back(ai);
                biggestodd = max(biggestodd, ai);
            }
        }

        if(odd.size()==0 || even.size()==0) {
            cout << no << endl;
            continue;
        }

        sort(even.begin(), even.end());

        ll esize = even.size();
        for(ll i=0; i<esize; i++) {
            if(biggestodd > even[i]) {
                biggestodd += even[i];
            }
            else {
                biggestodd += even[esize-1];
                i--;
            }
        
            no++;
        }

        cout << no << endl;
    }

    return 0;
}