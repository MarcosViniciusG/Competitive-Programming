#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()
signed main() 
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    
    vll nums(n);
    for(auto& p : nums) {cin >> p; if(p < 0) p*= -1;}

    vector<string> ans;
    for(auto p : nums) ans.push_back(to_string(p));

    vll check(10, 0);
    for(auto& p : ans)
    {
        int head = p[0]-'0';

        check[head]++;
    }

    auto it = max_element(all(check));
    int val = *it;
    int pos = it - check.begin();

    int total = 0;
    for(auto p : check)
    {
        if(p == val) total++;
    }

    if(pos == 1 && total == 1) cout << "unfortunately not\n";
    else cout << "suspicious\n";

    return 0;
}