// Find a subarray that sums up to target (only positive integers)

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll N, target, e, i, left_p, right_p, count=0, sum=0;
    vector<ll> v;

    cin >> N >> target;
    for(i=0; i<N; i++)
    {
        cin >> e;
        v.push_back(e);
    } 

    for(right_p=0, left_p=0; right_p < N;)
    {
        //cout << sum << " " << left_p << " " << right_p << endl;
        if(right_p==0)
        {
            sum = v[right_p];
        }
        if (sum==target) 
        {
            count++;
            right_p++;
            sum += v[right_p];
        }
        else if (sum < target) 
        {
            right_p++;
            sum += v[right_p];
        }
        else if (sum > target)
        {
            sum -= v[left_p];
            left_p++;
            if(left_p>right_p)
            {
                right_p++;
                sum += v[right_p];
            }
        } 
    }

    cout << count << endl;
    return 0;
}