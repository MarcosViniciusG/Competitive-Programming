#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()
#define int ll

ll counter = 0;
int consegui = 0;

ll smart_fact(ll n, ll k)
{
    ll t = n - k;
    ll total = 1;
    while(n > k)
    {
        total *= n;
        if(total % t == 0 && t)
        {
            total /= t;
            t--;
        }
        n--;
    }
    while(t) {total /= t; t--;}
    return total;
}

void backtracking(vll& nums, ll k, ll start, ll amount, ll total)
{
    if(consegui>k) return;

    if(amount >= k)
    {
        if(total > 100) counter++;
        else consegui++;
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

    sort(all(nums));

    backtracking(nums, k, 0, 0, 0);

    cout << smart_fact(n, k) - counter << '\n';

    return 0;
}
