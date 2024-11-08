#include <iostream>

using namespace std;
int main()
{
    long int t, i;
    long long int a, b;

    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> a >> b;

        if ((a+b) % 3 || (a==0 && b!=0) || (b==0 && a!=0) || ((a < b/2) || (b < a/2)))
            cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}