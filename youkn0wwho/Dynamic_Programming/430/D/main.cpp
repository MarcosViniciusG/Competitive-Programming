#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, W, wi, vi;

    vector<ll> w;
    vector<ll> v;

    cin >> N >> W;

    for(ll i=0; i<N; i++) {
        cin >> wi >> vi;
        w.push_back(wi);
        v.push_back(vi);
    }

    ll dp[N][W];

    for(ll x=1; x<=W; x++) {
        ll current = 0;

        for(ll i=0; i<N; i++) {
            if(x - w[i] > 0)
                dp[i][x] = 1;
            else
                dp[i][x] = 0;
        }
    }


    return 0;
}