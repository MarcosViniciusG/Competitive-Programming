#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin.ignore(1, '\n');
    getline(cin, S);

    queue<char> q;
    ll biggest = 1;
    ll ones=0;
    ll counter=1;
    for(ll i=0; i<N; i++) {
        char c = S[i];
        if(c=='/') {
            ll offset = 1;
            while((i - offset >= 0) && (i + offset < N) && S[i-offset]=='1' && S[i+offset]=='2') {
                counter += 2;
                offset++;
            }
            biggest = max(counter, biggest);
        }

        counter = 1;
    }

    cout << biggest << '\n';

    return 0;
}