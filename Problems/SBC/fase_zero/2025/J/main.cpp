#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main() 
{
    int n, k;
    cin >> n >> k;
    
    vector<int> xs(n*2), ys(n*2), ans(n);
    cin >> xs[0];
    xs[n] = xs[0];
    for(int i = 1; i < n; i++)
    {
        cin >> xs[i];
        xs[i+n] = xs[i];

        ys[i-1] = xs[i] - xs[i-1] - k;
        ys[i-1+n] = ys[i-1];
    }
    ys[n-1] = xs[0] - xs[n-1] - k;
    ys[2*n - 1] = ys[n-1];


    /* for(auto y : ys) cout << y << " ";
    cout << '\n'; */

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int delta[2*n+100] = {0};
    delta[0] = 0;
    for(int i = 0; i < 2*n; i++)
    {
        if(ys[i%n] < 0) ans[i%n] = (i+1)%n ;
        else if(i < n) {pq.push(make_pair(ys[i], i));}

        delta[i+1] = delta[i] + ys[i];
        while(!pq.empty() && (pq.top().first + (delta[i+1] - delta[pq.top().second+1]) < 0))
        {
            ans[pq.top().second] = (i+1)%n;
            pq.pop();
        }
    }

    for(auto p : ans) cout << p+1 << " ";
    cout << '\n';
}