#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    string palavra, ab;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> palavra;
        if(palavra.size() <= 10)
        {
            cout << palavra << endl;
            continue;
        }

        ab = "";

        ab += palavra[0];

        ab += to_string(palavra.size()-2);

        ab += palavra[palavra.size() - 1];

        cout << ab << endl;
    }
    return 0;
}