#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, p, v, t, problem, count=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        problem = 0;
        cin >> p >> v >> t;
        problem += p + v + t;
        if(problem >= 2) count++;
    }

    cout << count << endl;
    return 0;
}