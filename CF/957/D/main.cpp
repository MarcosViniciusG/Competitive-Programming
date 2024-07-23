#include <bits/stdc++.h>

using namespace std;

// Greedy solution
bool solve(int n, int m, int k, string s)
{
    // Considers the beginning and the ending as logs (you can jump from them M tiles)
    s = "L" + s + "L"; 

    int i=0, swam=0, j=0;
    while(i<=n)
    {
        // Starts with losing case
        if(s[i]=='C')
            break;

        // Swim case
        if(s[i]=='W') {
            i++;
            swam++;
            continue;
        }

        // Jump case
        bool jumped = false;

        for(j=min(i+m, n+1); j>i && !jumped; j--) {
            if(s[j]=='L')
            {
                i = j;
                jumped = true;
            }
        }

        if (jumped)
            continue;
        
        for(j=min(i+m, n+1); j>i && !jumped; j--) {
            if(s[j]=='W')
            {
                i = j;
                jumped = true;
            }
        }

        if(!jumped)
            break;
    }

    return (i > n && swam <= k);
}

int main()
{
    int t, n, m, k;
    cin >> t;
    string s;

    while(t--)
    {
        cin >> n >> m >> k;
        cin.ignore(1, '\n');
        getline(cin, s);
        bool can = solve(n, m, k, s);

        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}