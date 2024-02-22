#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    v.pop_back();
    for(auto e: v)
        cout << e << " ";
    cout << endl;
    return 0;
}