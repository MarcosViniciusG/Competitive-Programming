#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll s, n, x, y;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    bool possible = true;

    cin >> s >> n;
    while(n--)
    {
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    while(pq.size() != 0 && possible==true)
    {
        // cout << pq.top().first << endl;
        if(s <= pq.top().first)
            possible = false;

        s += pq.top().second;
        pq.pop();
    }

    if(possible)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}