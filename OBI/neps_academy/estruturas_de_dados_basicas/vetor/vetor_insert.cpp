#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    v.insert(v.begin()+0, 6); // Insere um elemento no começo "+0".
    v.insert(v.begin()+3, 10); // Insere um elemento na terceira posição "+3".
    for(auto e: v)
        cout << e << " ";
    cout << endl;

    return 0;
}