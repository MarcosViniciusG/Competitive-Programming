#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll digits;
        ll hist[10]={0};
        vll a(n);

        bool can=true;
        ll i=0;
        for(i=0; i<n; i++) 
            cin >> a[i];

        for(i=0; i<n; i++) { 
            can=true;
            hist[a[i]]++;

            for(ll j=0; j<10; j++) {
                if(j==0 && hist[j]<3)
                    can=false;
                if(j==1 && hist[j]<1)
                    can=false;
                if(j==2 && hist[j]<2)
                    can=false;
                if(j==3 && hist[j]<1)
                    can=false;
                if(j==5 && hist[j]<1)
                    can=false;
            }

            if(can)
                break;
        }

        if(!can)
            cout << 0 << '\n';
        else
            cout << i+1 << '\n';
    }


    return 0;
}