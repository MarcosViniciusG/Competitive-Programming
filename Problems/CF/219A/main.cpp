#include <bits/stdc++.h>

using namespace std;
int main()
{
    int k;
    string s, sol = "";
    cin >> k;
    cin.ignore(1, '\n');
    cin >> s;
    bool solution = true;
    map<char, int> counters;
    map<char, int> counters2;
    for (auto c : s)
    {
        if (counters.find(c) != counters.end())
            counters[c]++;
        else
            counters[c] = 1;

        counters2[c]=0;
    }

    bool change = true;

    while (change)
    {
        change = false;
        for (auto counter : counters)
        {
            if (counter.second % k)
            {
                solution = false;
                break;
            }

            for (int i = 0; i < (counter.second / k) && counter.second != counters2[counter.first]; i++)
            {
                change = true;
                sol += counter.first;
                counters2[counter.first]++;
            }
        }
    }

    if(solution)
        cout << sol << endl;
    else
        cout << -1 << endl;
    return 0;
}