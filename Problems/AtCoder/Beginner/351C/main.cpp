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

    vll A(N);
    for(ll &i: A)
        cin >> i;
    
    stack<ll> s;
    for(ll i=0; i<N; i++) {
        if((ll)s.size() < 1) {
            s.push(A[i]);
        }
        else {
            ll f = s.top();
            ll sec = A[i];
            if(f==sec) {
                while(f==sec && (ll)s.size()>0) {
                    s.pop();
                    sec = f+1;
                    if((ll)s.size()>0)
                        f = s.top();
                }
                s.push(sec);
            }
            else {
                s.push(A[i]);
            }
        }
    }

    cout << s.size() << '\n';

    return 0;
}