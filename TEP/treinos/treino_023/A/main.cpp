#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t, n, k, i;
    cin >> t;
    string s;
    while(t--)
    {
        s = "";
        i = 0;
        cin >> n >> k;
        while(n--)
        {
            if(i == k)
                i = 0;

            s += ('a' + i);

            i++;
        }

        cout << s << endl;
    }

    return 0;
}