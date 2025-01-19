#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, ai;
    cin >> t;

    while(t--) {
        cin >> n;
        vll A(n);

        for(ll &i: A)
            cin >> i;

        queue<ll> changes;
        for(ll i=0; i<n-1; i++) {
            if(A[i+1] < A[i]) {
                changes.push(i);
            }
        }

        bool can = true;

        for(ll i=0; i<n-1; i++) {
            if(A[i] <= A[i+1]) {
                A[i+1] -= A[i];
                A[i] = 0;

                if(!changes.empty() && changes.front()==i)
                    changes.pop();
            }
        }

        cout << (changes.empty() ? "YES" : "NO") << '\n';
    }

    return 0;
}