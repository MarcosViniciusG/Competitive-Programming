#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;

vector<int> coins {1, 3, 4};

// Complete search approach
// O(n^k)
int solve(int x) {
    if(x < 0) return INFINITY;
    if(x==0) return 0;
    int best = INFINITY;
    for(auto c: coins) {
        best = min(best, solve(x-c)+1);
    }
    return best;
}

// Memoization
// O(nk)
bool ready[N];
int value[N];

int solve_dp(int x) {
    if(x < 0) return INFINITY;
    if(x==0) return 0;
    if(ready[x]) return value[x];
    int best = INFINITY;
    for (auto c: coins) {
        best = min(best, solve(x-c)+1);
    }

    value[x] = best;
    ready[x] = true;
    return best;
}

// Iterative approach
int solve_iterative(int n) {
    value[0] = 0;
    for(int x=1; x<=n; x++) {
        value[x] = INFINITY;
        for(auto c: coins) {
            if(x-c >= 0) {
                value[x] = min(value[x], value[x-c]+1);
            }
        }
    }

    return value[n];
}

// Constructing  the solution (Coins used by order)
int first[N];

void solve_constructive(int n) {
    value[0] = 0;
    for(int x=1; x<=n; x++) {
        value[x] = INFINITY;
        for(auto c: coins) {
            if(x-c >= 0 && value[x-c]+1 < value[x]) {
                value[x] = value[x-c] + 1;
                first[x] = c;
            }
        }
    }

    while (n > 0) {
        cout << first[n] << "\n";
        n -= first[n];
    }
}

// Number of ways to construct the solution
int solve_ways(int n) {
    int count[n];
    count[0] = 1;
    for(int x=1; x<=n; x++) {
        for(auto c: coins) {
            if(x-c >= 0) {
                count[x] += count[x-c];
            }
        }
    }

    return count[n];
}

