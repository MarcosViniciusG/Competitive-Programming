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
    ll pre[N+1];
    ll suff[N+1];
    pre[0] = 0;
    suff[0] = 0;
    set<ll> st;
    for(ll i=0; i<N; i++) {
        cin >> A[i];
        st.insert(A[i]);
        pre[i+1] = st.size();
    }

    st.clear();
    for(ll i=N-1; i>=0; i--) {
        st.insert(A[i]);
        suff[N-i] = st.size();
    }

    ll best=0;
    for(ll i=1; i<=N; i++) {
        best = max(best, suff[N-i]+pre[i]);
    }

    cout << best << '\n';

    return 0;
}