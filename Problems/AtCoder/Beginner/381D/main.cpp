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

    if(N==1) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans=0;
    ll F[N];

    // Stores greatest position for each value between 1 and N, such that
    // pos[x] is the maximum index that x appears in a 1122 sequence
    vll pos(N+1, -1);

    // Sequences such that the 1122 sequence finishes
    // in a odd-indexed number
    if(A[0]==A[1]) {
        F[1] = 0;
        pos[A[0]] = 0;
        ans = 2;
    }
    else {
        F[1] = 2;
    }

    for(ll r=3; r<N; r+=2) {
        if(A[r-1]!=A[r])
            F[r] = r+1;
        else if(A[r-1]==A[r]) {
            if(pos[A[r-1]]>=F[r-2])
                F[r] = pos[A[r-1]] + 2;
            else
                F[r] = F[r-2];

            pos[A[r-1]] = r-1;
        }
        ans = max(ans, r - F[r] + 1);     
    }

    // Sequences such that the 1122 sequence finishes
    // in a even-indexed number
    fill(pos.begin(), pos.end(), -1);
    if(A[1]==A[2]) {
        F[2] = 1;
        pos[A[1]] = 1;
        ans = max(ans, 2LL);
    }
    else {
        F[2] = 3;
    }

    for(ll r=4; r<N; r+=2) {
        if(A[r-1]!=A[r])
            F[r] = r+1;
        else if(A[r-1]==A[r]) {
            if(pos[A[r-1]]>=F[r-2])
                F[r] = pos[A[r-1]] + 2;
            else
                F[r] = F[r-2];

            pos[A[r-1]] = r-1;
        }
        ans = max(ans, r - F[r] + 1);     
    }
    
    cout << ans << '\n';
    return 0;
}