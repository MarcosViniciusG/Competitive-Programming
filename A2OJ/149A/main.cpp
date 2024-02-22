#include <bits/stdc++.h>

using namespace std;
int main()
{
    int k, a, i, counter=0, sum=0;
    priority_queue<int, vector<int>> pq;
    cin >> k;
    for(i=0; i<12; i++)
    {
        cin >> a;
        pq.push(a);
    }

    while(pq.size()!=0 && sum < k)
    {
        sum += pq.top();
        counter++;
        pq.pop();
    }

    if(sum>=k)
        cout << counter << endl;
    else
        cout << -1 << endl;
    return 0;
}