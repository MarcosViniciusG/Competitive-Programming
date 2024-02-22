#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    
    v.push_back(6); // Insere um elemento no final do vetor. O(1)
    for(auto e: v)
        cout << e << " ";
    cout <<  endl;
    return 0;
}