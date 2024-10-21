#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n){
    if(n==1)
        return 1;
    else
        return n * solve(n-1);
}

int main() {
    ll N;
    cin >> N;

    cout << solve(N) << endl;
}