#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cartesian_product(vector<int> m, vector<int> n)
{
    vector<vector<int>> mn;
    for(int i=0; i<m.size(); i++)
    {
        vector<int> temp;
        temp.push_back(m[i]);
        for(int j=0; j<n.size(); j++)
        {
            temp.push_back(n[j]);
            mn.push_back(temp);
            temp.pop_back();
        }
    }

    return mn;
}

int main()
{
    vector<int> m{5, 2, 6, 9};
    vector<int> n{10, 14, 4};

    vector<vector<int>> mn = cartesian_product(m, n);

    for(int i=0; i<mn.size(); i++)
    {
        for(int j=0; j<mn[i].size(); j++)
        {
            cout << mn[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}