#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll t, n, ai;

    cin >> t;
    while(t--) {
        cin >> n;
        ll a[n];
        memset(a, 0, sizeof(a));
        bool can = true;

        for(ll i=0; i<n; i++) {
            cin >> ai;
            ai--;

            a[ai] = 1;

            if(i==0)
                continue;
            
            if(ai==0 && a[1]==0)
                can = false;
            else if(ai==(n-1) && a[n-2]==0)
                can = false;
            else if(a[ai-1]==0 && a[ai+1]==0)
                can = false;
        }

        if(can)
            cout << "Yes\n";
        else
            cout << "No\n";

    }

    return 0;
}