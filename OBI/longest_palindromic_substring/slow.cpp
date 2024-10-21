#include <bits/stdc++.h>

using namespace std;

vector<int> manacher_odd(int n, string s)
{
    s = "$" + s + "^";
    vector<int> p(n+2);
    for(int i=1; i<=n; i++)
    {
        while (s[i-p[i]] == s[i+p[i]])
        {
            p[i]++;
        }
    }

    return vector<int>(begin(p) + 1, end(p) - 1);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    string t;
    cin >> t; 
    return 0;
}