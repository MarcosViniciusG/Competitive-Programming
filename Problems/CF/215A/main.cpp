#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n, m, counter=0, max=0;

    cin >> n;
    int pedal[n];
    for(int i=0; i<n; i++) 
        cin >> pedal[i];

    cin >> m;
    int wheel[m];
    for(int j=0; j<m; j++)
    {
        cin >> wheel[j];
        for(int i=0; i<n; i++)
        {
            if(wheel[j] % pedal[i] == 0)
            {
                if(wheel[j] / pedal[i] > max)
                {
                    max = wheel[j] / pedal[i];
                    counter=1;
                }
                else if(wheel[j] / pedal[i] == max)
                {
                    counter++;
                } 
            }
        }
    }

    cout << counter << endl;
    return 0;
}
