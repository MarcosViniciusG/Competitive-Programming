#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> l = {1, 10, 2, 3};
    auto ptr = l.begin();

    int pos=1;
    while(pos!=2)
    {
        ptr++;
        pos++;
    }

    l.erase(ptr);
    for(auto e: l)
    {
        cout << e << " ";
    }
    cout<< endl;

    return 0;
}