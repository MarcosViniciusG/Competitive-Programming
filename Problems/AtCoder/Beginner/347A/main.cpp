#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector <ll >
#define pll pair <ll , ll >
#define vpll vector <pll >
#define endl '\n'
#define all(xs) xs. begin () , xs.end ()
#define found (x, xs) (xs. find (x) != xs.end ())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, K, Ai;
    cin >> N >> K;
    for(ll i=0; i<N; i++) {
        cin >> Ai;
        if(Ai % K==0)
            cout << Ai / K << ' ';
    }
    cout << "\n";

    return 0;
}