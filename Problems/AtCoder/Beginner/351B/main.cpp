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
    ll N;
    cin >> N;
    cin.ignore(1, '\n');

    string A[N];
    for(ll i=0; i<N; i++)
        getline(cin, A[i]);
    
    ll r=-1, c=-1;
    string B[N];
    for(ll i=0; i<N; i++) {
        getline(cin, B[i]);
        for(ll j=0; j<N; j++) {
            if(B[i][j] != A[i][j]) {
                r = i+1;
                c = j+1;
            }
        }
    }

    cout << r << ' ' << c << '\n';

    return 0;
}