#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll N, ni;
    cin >> N;

    vll n(N);

    ll current_sum=0;
    ll best_sum= ll(-INFINITY);
    for(ll &i: n) { 
        cin >> i;
        current_sum = max(i, current_sum+i);
        best_sum = max(current_sum, best_sum);
    }

    cout << best_sum << '\n';
    

    return 0;
}