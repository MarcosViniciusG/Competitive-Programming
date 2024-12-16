#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, b, a) for (ll i = (b); i >= (a); --i)
#define x first
#define y second

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N;
    ll Ai, Bi;
    ll K, L;
    vll A;
    vll B;
    cin >> N;

    ll prefixes[N+1];
    prefixes[0] = 0;
    for(ll i=0; i<N; i++) {
        cin >> Ai;
        A.push_back(Ai);
    }

    for(ll i=0; i<N; i++) {
        cin >> Bi;
        B.push_back(Bi);
    }

    for(ll i=0; i<N; i++) {
        prefixes[i+1] = prefixes[i] + A[i] + B[i];
    }

    cin >> K >> L;

    ll suff[N+1];
    suff[0] = 0;
    for(ll i=N-1, j=1; i>=0; i--, j++) {
        suff[j] = suff[j-1] + A[i] + B[i]; 
    }

    ll melhor_soma = 0;
    ll melhor_i = 0; 
    for(ll i=K; i>=0; i--) {
        ll soma = (prefixes[i] + suff[K - i]);
        if(soma >= melhor_soma) {
            melhor_soma = soma;
            melhor_i = i;
        }
    }

    ll ans=0;
    vector<ll> bs;
    ll k=K;
    for(ll i=0; i<melhor_i; i++) {
        ans += A[i];
        k--;

        bs.push_back(B[i]);
    }

    ll j=N-1;
    while(k!=0) {
        ans += A[j];

        bs.push_back(B[j]);
        j--;
        k--;
    }

    sort(bs.begin(), bs.end(), greater<ll>());
    for(ll i=0; i < L; i++)
        ans += bs[i];

    cout << ans << '\n';
    return 0;
}