#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a, diff=0;
    vector<int> v;
    cin >> n;

    while(n--)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i+=2)
    {
        diff += (v[i+1] - v[i]);
    }

    cout << diff << endl;
    return 0;
}