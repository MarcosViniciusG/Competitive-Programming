#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

vll histogram(const string &s) {
    vll hist(26, 0);
    for(auto c: s)
        hist[c-'a']++;
    
    return hist;
}

signed main() {
    string S;
    getline(cin, S);
    int n = S.size();

    bool is_even = !(n & 1);
    bool equality = true;
    bool twice = true;

    for(ll i=0; i<(n/2); i++) {
        if(S[2*i]!=S[2*i + 1])
            equality = false;
    }

    vll hist = histogram(S);
    for(auto e: hist) 
        if(e != 2 && e != 0)
            twice = false;

    if(is_even && equality && twice)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}