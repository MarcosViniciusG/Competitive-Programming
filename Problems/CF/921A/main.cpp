#include <bits/stdc++.h>

using namespace std;
const int MAXN = 26;
int n, k;
const char ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        string ans = "";
        cin >> n >> k;
        for(int j=0; j<n; j++)
        {
            for(int m=0; m<k; m++)
            {
                ans += ALPHABET[m];
            }
        }

        cout << ans << endl;
    }

    return 0;
}