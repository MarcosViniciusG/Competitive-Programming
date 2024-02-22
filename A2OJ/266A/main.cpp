#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, count=0;
    string stones;
    cin >> n;
    cin.ignore(1, '\n');
    cin >> stones;

    vector<int> mask(n, 1);

    for(int i=0; i<n; i++)
    {

        if(i!=n-1 && stones[i+1]==stones[i] && mask[i+1]==1)
        {
            mask[i+1] = 0;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}