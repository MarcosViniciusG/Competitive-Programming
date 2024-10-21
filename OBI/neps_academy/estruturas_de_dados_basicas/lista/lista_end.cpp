#include <bits/stdc++.h>

using namespace std;
int main()
{
    list<int> l = {1, 2, 3};

    auto ptr = l.end();

    ptr--;

    cout << *ptr << endl;

    return 0;
}