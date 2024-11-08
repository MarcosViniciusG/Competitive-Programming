#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll minimum = -1;
vector<ll> apples;
void backtracking(int i, bool chosen[])
{
    if(i==n)
    {
        ll sum1=0;
        ll sum2=0;
        for(int j=0; j<n; j++)
        {
            if(chosen[j])
                sum1 += apples[j];
            else
                sum2 += apples[j];             
        }
        if(minimum==-1)
            minimum = abs(sum1 - sum2);
        else
            minimum = min(minimum, abs(sum1-sum2));

        return;
    }

    chosen[i] = true;
    backtracking(i+1, chosen);
    
    chosen[i] = false;
    backtracking(i+1, chosen);
}

int main()
{
    ll a;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        apples.push_back(a);
    }
    bool chosen[n];
    memset(chosen, false, sizeof(chosen));

    backtracking(0, chosen);
    cout << minimum << endl;
    return 0;
}