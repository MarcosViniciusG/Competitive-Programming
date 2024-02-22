#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};

    v.erase(v.begin()+1);
    for(auto e: v)
        cout << e << " ";
    cout << endl;

    return 0;
}