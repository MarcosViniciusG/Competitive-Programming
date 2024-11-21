#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

const ll MAXN = ll(2*ll(1e5) + 1);

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        if(n < 5) {
            cout << -1 << '\n';
            continue;
        }

        vll odds, evens;
        for(int i=1; i<=n; i++) {
            if(i!=5 && (i & 1))
                odds.push_back(i);
            else if(i!=4 && !(i&1))
                evens.push_back(i);
        }

        vll solution;
        for(auto odd: odds)
            solution.push_back(odd);
        
        solution.push_back(5);

        solution.push_back(4);

        for(auto even: evens)
            solution.push_back(even);

        for(auto e: solution)
            cout << e << ' ';

        cout << '\n';
    }
    
    return 0;
}