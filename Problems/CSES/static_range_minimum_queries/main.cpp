#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Preprocessing: minq(a, b) = min(minq(a, a+w-1), minq(a+w, b))
// b-a+1 = 2^x
// w = (b-a+1) / 2
// O (n log n)

const int MAXN = 200000;
const int K = 25;

ll dp[K][MAXN+1];
ll lg[MAXN+1];

void minq(ll a, ll b) {
    int w = (b-a+1)/2;
    cout << a << " " << b << endl;

    ll l = lg[w];
    
    if(a+w > b || w==0) return;

    minq(a, a+w-1);
    minq(a+w, b);


    dp[l][a] = min(dp[l][a], dp[l][a+w]);
}

int main()
{   
    // O (maxn)
    lg[1] = 0;
    for (ll i = 2; i <= 200001; i++)
        lg[i] = lg[i/2] + 1;

    ll n, q, xi, a, b;
    cin >> n >> q;

    for(ll i=0; i<n; i++) {
        cin >> xi;
        dp[0][i] = xi;
    }

    for (ll i = 0; i < n; i++) {
        minq(i, pow(2, lg[n])-1);
    }

    for(ll i=0; i<=lg[n]; i++)
    {
        for(ll j=0; j<n; j++) {
        
            if(j + pow(2, i) - 1 < n)
                cout << j << " " << pow(2, i) + j - 1 << " " << dp[i][j] << endl; 
        }
    }

    while(q--) {
        cin >> a >> b;
        ll l = lg[b-a+1];
        cout << min(dp[l][a-1], dp[l][b- (l/2) + 1]) << endl;
    }

    return 0;
}