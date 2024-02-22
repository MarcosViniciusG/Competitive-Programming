#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void merge(ll l, ll r, vector<ll> &v)
{
    ll mid = (l + r) / 2;
    vector<ll> S;

    ll p1 = l;
    ll p2 = mid+1;

    while(p1<= mid && p2 <= r)
    {
        if(v[p1] >= v[p2])
        {
            S.push_back(v[p1]);
            p1++;
        }

        else
        {
            S.push_back(v[p2]);
            p2++;
        }  
    }

    while(p1 <= mid)
    {
        S.push_back(v[p1]);
        p1++;
    }

    while(p2 <= r)
    {
        S.push_back(v[p2]);
        p2++;
    }

    for(int i=0; i<S.size(); i++)
    {
        v[l + i] = S[i];
    }
}

void mergeSort(ll l, ll r, vector<ll>& v)
{   
    ll mid;

    if(l < r)
    {
        mid = (l + r) / 2;
        mergeSort(l, mid, v);
        mergeSort(mid+1, r, v);
        merge(l, r, v);
    }
}

int main()
{
    ll a, n;
    vector<ll> v;
    
    cin >> n;
    for(ll i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    mergeSort(0, n-1, v);
    for(auto e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}