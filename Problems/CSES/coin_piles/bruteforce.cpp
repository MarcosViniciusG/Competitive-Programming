#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    long int t, i;
    long long int a, b;

    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> a >> b;
        while (a!=0 && b!=0 && (a!=1 || b!=1))
        {
            if(a>b)
            {
                a-=2;
                b-=1;
            }
            else if(b>a)
            {
                b-=2;
                a-=1;
            }
            else
            {
                a-=2;
                b-=1;
            }
        }

        if(a==0 && b==0)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

    return 0;
}