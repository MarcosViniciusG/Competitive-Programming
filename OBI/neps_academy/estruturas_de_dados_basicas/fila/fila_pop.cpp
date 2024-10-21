#include <bits/stdc++.h>

using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);

    q.pop();
    cout << q.front() << endl;
    return 0;
}