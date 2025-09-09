// Pilha monótona
// O(n)

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
    ll n;
    cin >> n;
    vll a(n);
    stack<pll> st;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(st.empty()) {
            cout << 0 << ' ';
        }
        else {
            while(!st.empty() && st.top().first >= a[i]) {
                st.pop();
            }

            if(st.empty()) {
                cout << 0 << ' ';
            }
            else {
                cout << st.top().second << ' ';
            }
        }
        st.push({a[i], i+1});
    }
    cout << '\n';

    return 0;
}