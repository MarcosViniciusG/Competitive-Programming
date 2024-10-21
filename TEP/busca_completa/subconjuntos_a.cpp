#include <bits/stdc++.h>

using namespace std;

vector<int> conjunto {4, 2, 10};
vector<int> subconjunto;

void search(int k)
{
    if(k==conjunto.size())
    {
        for(int i=0; i < subconjunto.size(); i++)
        {
            cout << subconjunto[i] << " ";
        }
        cout << endl;
    }
    else
    {
        search(k+1);
        subconjunto.push_back(conjunto[k]);
        search(k+1);
        subconjunto.pop_back();
    }
}

int main()
{
    search(0);
    return 0;
}