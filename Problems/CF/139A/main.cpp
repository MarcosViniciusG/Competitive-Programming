#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, day;
    map<int, int> week;

    cin >> n;
    for(int i=0; i<7; i++)
    {
        cin >> day;
        if(day) week[i] = day;
    }

    while(n > 0)
    {
        for(auto par: week)
        {
            n -= par.second;
            if(n <= 0) 
            {
                day = par.first + 1;
                break;
            } 
        }
    }

    cout << day << endl;
}