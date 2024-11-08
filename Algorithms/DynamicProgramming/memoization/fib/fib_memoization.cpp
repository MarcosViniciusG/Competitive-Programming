#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fib(ll n, ll memo[10001]) {
    if(n==1 || n==2) 
        return memo[n] = 1;

    if(memo[n-2] == -1)
        memo[n-2] = fib(n-2, memo);

    if(memo[n-1] == -1)
        memo[n-1] = fib(n-1, memo);

    return memo[n] = memo[n-1] + memo[n-2];
}

int main() {
    ll memo[10001];

    memset(memo, -1, sizeof(memo));

    cout << fib(20, memo) << endl;
    cout << fib(50, memo) << endl;
    cout << fib(9999, memo) << endl;
}