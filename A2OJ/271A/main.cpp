#include <bits/stdc++.h>

using namespace std;
int main()
{
    string y, year;
    cin >> y;
    bool beaut = false;
    while(beaut==false)
    {
        beaut = true;

        int y_i = stoi(y);
        y_i++;
        y = to_string(y_i);
        for(int i=0; i<4; i++)
        {
            for(int j=i+1; j<4; j++)
            {
                if(y[i] == y[j]) beaut = false;
            }
        }

        if(beaut) year = y;
    }

    cout << year << endl;
    return 0;
}