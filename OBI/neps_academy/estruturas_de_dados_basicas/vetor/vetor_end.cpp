#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};

    auto ptr = v.end();
    ptr--;

    cout << *ptr << endl;

    return 0;
}