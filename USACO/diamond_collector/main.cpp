#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k, a, counter, biggest=1;
    vector<int> diamonds;
    cin >> n >> k;

    while(n--)
    {
        cin >> a;
        diamonds.push_back(a);
    }

    for(int i=0; i<diamonds.size(); i++)
    {
        counter=1;
        for(int j=i+1; j<diamonds.size(); j++)
        {
            if(abs(diamonds[i] - diamonds[j]) <= k) counter++;
        }
        
        biggest = max(counter, biggest);
    }

    cout << biggest << endl;
}