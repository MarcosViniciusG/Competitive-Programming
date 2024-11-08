#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    ll N, K, Ai;

    vll A;
    cin >> N >> K;

    for(ll i=0; i<N; i++) {
        cin >> Ai;
        A.push_back(Ai);
    }

    sort(A.begin(), A.end());

    
    ll minSum = 2e9;
    for(int i=0;i<=K;i++){
        minSum=min(minSum,A[i+(N-K)-1]-A[i]);
    }

    cout << minSum << endl;
    return 0;
}