#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    v.resize(2, 4);
    for(auto e: v)
        cout << e << " ";
    cout << endl;

    v.resize(5, 3);
    for(auto e: v)
        cout << e << " ";
    cout << endl;

    return 0;
}