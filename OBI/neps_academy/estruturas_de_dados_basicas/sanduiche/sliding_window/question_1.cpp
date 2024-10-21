// Maximum subarray

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll i, n, k, e, left_p, right_p, max_sum, sum=0;
    vector<ll> v;

    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> e;
        v.push_back(e);
        if(i < k) sum += e; 
    }

    max_sum = sum;

    for(right_p=k, left_p=0; right_p < n; left_p++, right_p++)
    {
        sum -= v[left_p];
        sum += v[right_p];
        if(sum > max_sum) max_sum = sum;
    }

    cout << max_sum << endl;
}