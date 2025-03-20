#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll diry[] = {2, 2, -2, -2, 1, 1, -1, -1};
ll dirx[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
    int n;
    cin >> n;

    ll ans[n+1];
    for(ll k=1; k<=n; k++) {
        ans[k] = (k*k)*(k*k - 1);
        ans[k] /= 2;
    }

    ll sub[n+1];
    sub[0] = 0;
    sub[1] = 0;
    for(ll k=2; k<=n; k++) {
        ll res=0;
        for(ll i=1; i<=k; i++) {
            for(int d=0; d<4; d++) {
                ll ni=i+diry[d], nj=k+dirx[d*2+1];
                if(ni > k || ni <= 0) continue;
                if(nj > k || nj <= 0) continue;

                res++;
            }
        }

        res*=2;

        sub[k] = sub[k-1] + res;
        ans[k] -= sub[k];
    }

    for(ll k=1; k<=n; k++)
        cout << ans[k] << '\n';
    

    return 0;
}