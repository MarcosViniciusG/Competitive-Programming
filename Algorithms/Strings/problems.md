## Standout Problems

### Permalex

Returns the position of a given string in regards to all of its possible permutations, in lexicographical order.

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll getPermutation(map<char,int>& charcount)
{
    ll total = 0, mult_total = 1;
    map<char, int> mp = charcount;
    for(auto pair : charcount)
    {
        total += pair.second;
    }
    for(int i = total; i >= 1; i--)
    {
        mult_total *= i;
        for(auto pair : mp)
        {
            if(i == pair.second)
            {
                mult_total /= pair.second;
                mp[pair.first]--;
            }
        }
    }

    return mult_total;
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
    while(getline(cin, s), s != "#")
    {
        ll pos = solve(s);
        printf("%10lld\n", pos);
    }

    return 0;
}
```