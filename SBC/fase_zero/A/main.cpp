#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int arr[] = {0, 0, 0};
    if(n1)
        arr[n1-1] = 1;
    if (n2)
        arr[n2-1] = 1;
    if (n3)
        arr[n3-1] = 1;

    for(int i=0; i<3; i++)
    {
        if(!arr[i])
        {
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}