#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, x=0;
    string operation;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> operation;
        cin.ignore(1, '\n');

        for(auto c: operation)
        {
            if(c=='+')
            {
                x++;
                break;
            }
            else if(c=='-')
            {
                x--;
                break;
            }
        }
    }

    cout << x << endl;

    return 0;
}