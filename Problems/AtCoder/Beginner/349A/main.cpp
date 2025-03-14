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
    ll score=0;
    ll N;
    cin >> N;

    ll A[N-1];
    for(auto i: A) {
        cin >> i;
        score += -i;
    }
    
    cout << score << '\n';

    return 0;
}