#include <bits/stdc++.h>

using namespace std;

int n=3;
vector<int> permutation;
vector<bool> chosen (n, false);

void search()
{
    if(permutation.size()==n)
    {
        for(int i=0; i<n; i++)
        {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();

        }
    }
}

int main()
{
    search();
    return 0;
}