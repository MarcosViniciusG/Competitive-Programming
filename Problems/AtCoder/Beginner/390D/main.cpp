#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

unordered_set<ll> values;
ll val;
vll A;
vll S;
ll N;

void solve(ll d, ll k) {
    for(ll i=0; i<=k; i++) {
        val ^= S[i]; // Removes the old sum of group i from val
        S[i] += A[d]; // Group i now has stones from bag d
        val ^= S[i]; // Adds the new sum of group i to val
        if(d==N-1) 
            values.insert(val); // If all bags are in groups, add the value
        else if(i<k)
            solve(d+1, k); // Go assign the next bag to an existing group
        else   
            solve(d+1, k+1); // Create a new group and go assign the next bag

        // Undo the changes to val and S[i] to restore the 
        // previous state before moving to the next iteration
        val ^= S[i];
        S[i] -= A[d];
        val ^= S[i];
    }

    return;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    ll ai;

    for (ll i = 0; i < N; i++) {
        cin >> ai;
        A.push_back(ai);
        S.push_back(0);
    }
    
    val = 0;
    solve(0, 0);

    cout << values.size() << '\n';
    return 0;
}