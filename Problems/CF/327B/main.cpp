#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e7 + 1;

// O(MAX * sqrt(MAX))
bool isPrime(ll n)
{
    // Check if n is divisible by 2
    if(n % 2==0)
        return false;

    // Check only odd numbers
    for(ll d=3; d*d <= n; d+=2)
    {
        if(n % d==0)
            return false;
    }
    return n >= 2;
}

int main()
{
    int n;
    cin >> n;

    vector<ll> nums;
    nums.push_back(2);    
    for(ll i=3; i<MAX && nums.size() < n; i+=2)
    {
        if(isPrime(i))
            nums.push_back(i);
    } 

    for(auto num: nums)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}