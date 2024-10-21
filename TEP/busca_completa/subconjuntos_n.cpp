#include <bits/stdc++.h>

using namespace std;
vector<int> subset;
int n=3;

void search(int k)
{
    if(k==n)
    {
        for(int i=0; i<subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << endl;
    }
    else
    {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }

}

int main()
{
    search(0);
    return 0;
}