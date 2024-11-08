#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, town, min, idx;
    bool travel=true;
    cin >> n;
    for(ll i=0; i<n; i++)
    {
        cin >> town;
        if(i==0 || town<min)
        {
            min = town;
            idx = i;
            travel = true;
        }
        else if(town==min)
        {
            travel = false;
        }
    }

    if(travel)
        cout << idx + 1 << endl;
    else
        cout << "Still Rozdil\n";

    return 0;
}