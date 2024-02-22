#include <bits/stdc++.h>

using namespace std;

int n;

void rev(vector<int>& perm, int i)
{   
    if(i==n) return;

    rev(perm, i+1);
    swap(perm[i-1], perm[i]);

}

int main()
{
    cin >> n;
    vector<int> perm;
    for(int i=1; i<=n; i++)
        perm.push_back(i);

    rev(perm, 1);
    
    for(auto e: perm)
        cout << e <<  " ";
    cout << endl;
    
    return 0;
}