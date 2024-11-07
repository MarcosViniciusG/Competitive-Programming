#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int MAXN = 31;

ll getPermutation(map<char,int>& charcount)
{
    ll total = 1;

    ll n_elements=0;

    map<char, int> mp = charcount;

    // cout << "PARES\n";
    for(auto pair : charcount)
    {
        // cout << pair.first << " " << pair.second << '\n';
        n_elements+=(pair.second);
    }
    // cout << '\n';

    for(int i=n_elements; i>=1; i--) {
        // cout << total << " * " << i << '\n';
        total*=i;

        for(auto pair : mp)
        {   
            if(i==pair.second) {
                // cout << total << " / " << pair.second << '\n';
                total /= pair.second;
                mp[pair.first]--;
            }
        }
    }
    // cout << "pre-factorial total: " << total << endl;
    // cout << "pre-div factorial total : " << abs(factorials[total]) << endl;
    // total = abs(factorials[total]) / denominator;

    // cout << "post-div total: " << total << " denominator: " << denominator << endl;

    return total;
}//zzzzzzzzzzzzzzaaaaaaaaaaaaaa

ll solve(const string& s)
{
    map<char, int> charcount;
    ll position = 1;
    for(auto x : s)
    {
        charcount[x]++;
    }

    int len = s.length();
    for(int i = 0; i < len; i++)
    {
        char curr = s[i];
        
        for(auto pair : charcount)
        {
            char small = pair.first;
            if(small >= curr) break;

            if(charcount[small] > 0)
            {   
                charcount[small]--;
                position += abs(getPermutation(charcount));
                // cout << position << '\n' << '\n';
                charcount[small]++;
            }
        }

        charcount[curr]--;
        if(charcount[curr] == 0)
        {
            charcount.erase(curr);
        }
    }

    return position;
}

int main()
{
    string s;

    while (getline(cin, s), s!="#")
    {
        ll pos = solve(s);
        printf("%10lld\n", pos);
    }
    
    return 0;
}