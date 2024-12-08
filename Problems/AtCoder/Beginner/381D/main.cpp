#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

const int MAXN = 200010;

signed main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &i: A)
        cin >> i;

    ll f[N];
    if(A[0]==A[1])
        f[1] = 0;
    else
        f[1] = 2; 

    for(ll r=3; r<N; r+=2) {
        if(A[r]!=A[r-1])
            f[r] = r+1;
        else {
            ll k=f[r-2];
            for(ll off=0; k+off<=r-3; off+=2) {
                if(A[k+off]==A[r-1]) {

                }
            }

            if(k==f[r-2])
                f[r] = f[r-2];
            else
                f[r] = k + 2;
        }

    }

  
    return 0;
}