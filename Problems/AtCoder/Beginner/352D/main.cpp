#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

signed main() {
    fastio;
    ll N, K;
    cin >> N >> K;

    ll ai;
    ll idxs[N];
    for(ll i=0; i<N; i++) {
        cin >> ai;
        ai--;
        idxs[ai] = i;
    }

    vll mx;
    vll mn;
    deque<ll> dqmx, dqmn;

    for(ll i=0; i<K; i++) {

        while(!dqmx.empty() && idxs[i] > idxs[dqmx.back()])
            dqmx.pop_back();
        
        dqmx.push_back(i);

        while(!dqmn.empty() && idxs[i] < idxs[dqmn.back()])
            dqmn.pop_back();
        
        dqmn.push_back(i);
    }

    for(ll i=K; i<=N; i++) {
        mx.push_back(idxs[dqmx.front()]);
        mn.push_back(idxs[dqmn.front()]);

        // Remove idxs from queue that are out of range
        while(!dqmx.empty() && dqmx.front() <= i-K)
            dqmx.pop_front();
        
        while(!dqmn.empty() && dqmn.front() <= i-K)
            dqmn.pop_front();

        // Remove useless elements from the back of the queue
        // (smaller than the current element)
        while(!dqmx.empty() && idxs[i] > idxs[dqmx.back()])
            dqmx.pop_back();
        
        dqmx.push_back(i);

        while(!dqmn.empty() && idxs[i] < idxs[dqmn.back()])
            dqmn.pop_back();
        
        dqmn.push_back(i);
    }

    ll ans=N;
    for(ll i=0; i<(ll)mx.size(); i++) {
        ans = min(ans, mx[i] - mn[i]);
    }

    cout << ans << '\n';

    return 0;
}