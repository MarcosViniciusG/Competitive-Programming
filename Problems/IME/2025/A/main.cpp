#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

int counter = 0;

void backtracking(vll& nums, int k, int start, int amount, int total)
{
    if(amount >= k)
    {
        if(total <= 100) counter++;
        return;
    }
    if(start >= nums.size()) return;

    backtracking(nums, k, start+1, amount, total);

    total += nums[start];
    amount++;

    backtracking(nums, k, start+1, amount, total);
}

signed main() 
{
    ll n, k;
    cin >> n >> k;
    
    vll nums(n);
    for(auto& p : nums) cin >> p;

    backtracking(nums, k, 0, 0, 0);

    cout << counter << '\n';

    return 0;
}
