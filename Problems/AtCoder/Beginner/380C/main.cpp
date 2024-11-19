#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, K;
    string S;
    cin >> N >> K;
    cin.ignore(1, '\n');
    getline(cin, S);

    ll end_k_minus_one=0;
    ll start_k=0;
    ll end_k = N;
    ll k = 0;
    bool seq=0;
    for(ll i=0; i<N; i++) {
        if(S[i]=='1' && !seq) {
            k++;
            seq=true;
            if(k==K)
                start_k=i;
        }
        else if(S[i]=='0' && seq) {
            seq = false;
            if(k==K-1)
                end_k_minus_one=i;
            else if(k==K)
                end_k = i;
        }
    }

    ll diff = end_k - start_k;
    for(ll i=end_k_minus_one; i<end_k; i++) {
        if(diff) {
            S[i]='1';
            diff--;
        }
        else
            S[i]='0'; 
    }

    cout << S << '\n';
    return 0;
}