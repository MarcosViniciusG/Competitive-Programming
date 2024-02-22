#include <bits/stdc++.h>

using namespace std;
int main()
{
    priority_queue<int, vector<int>> pq;
    pq.push(1);
    pq.push(4);
    pq.push(2);

    cout << "Topo: " << pq.top() << endl;
    pq.push(0);

    cout << "Topo: " << pq.top() << endl;

    pq.pop();
    cout << "Topo: " << pq.top() << endl;

    cout << "Tamanho: " << pq.size() << endl;
    return 0;
}