#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()
signed main() 
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    ll t;
    cin >> t;
    cin.ignore(1, '\n');
    while(t--) {
        string n;
        getline(cin, n);

        if(n[0]=='-')
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}