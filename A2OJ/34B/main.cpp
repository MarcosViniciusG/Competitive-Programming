#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, a, sum=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n >> m;
    while(n--)
    {
        cin >> a;
        pq.push(a);
    }

    for(int i=0; i<m && pq.top() <= 0; i++)
    {
        sum -= pq.top();
        pq.pop();
    }
    cout << sum << endl;

    return 0;
}