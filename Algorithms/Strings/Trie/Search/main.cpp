#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Node = map<char, ll>;
using Trie = vector<Node>;
using vll = vector<ll>;

Trie build(const string& s)
{
    ll next=0, deepest=0;
    string S = s+'#';
    vll suf {-1};
    Trie trie(1);

    for(size_t i=0; i<S.size(); i++)
    {
        char c = S[i];
        ll u = deepest;

        while(u >= 0)
        {
            auto it = trie[u].find(c);

            if(it == trie[u].end())
            {
                trie.push_back({ });
                trie[u][c] = ++next;

                suf.push_back(0);

                if(u != deepest)
                    suf[next-1] = next;
                else
                    deepest = next;
            }
            else
            {
                suf[next] = it->second;
                break;
            }
            u = suf[u];
        }
    } 

    return trie;
}

bool search(const Trie& trie, const string& s) {
    ll v=0;

    for(auto c: s)
    {
        auto it = trie[v].find(c);

        if(it==trie[v].end())
            return false;
        
        v = it->second;
    }

    return true;
}

signed main() {
    string a, b;
    cin >> a >> b;
    Trie trie = build(a);

    cout << (search(trie, b) ? "YES" : "NO") << '\n';

    return 0;
}