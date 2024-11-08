#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N_CHARS = 256;

// n = s.size()
// O(n)

bool canFormPalindrome(string s)
{
    ll counters[N_CHARS] = {0}; 
    for(auto c: s) {
        counters[c]++;
    }

    ll odd = 0;
    for(ll i=0; i<N_CHARS && odd < 2; i++) {
        if(counters[N_CHARS] % 2 != 0)
            odd++;
    }

    return odd < 2;
}

// n = s.size()
// O(n)

int minNumberRemoval(string s)
{
    ll counters[N_CHARS] = {0}; 
    for(auto c: s) {
        counters[c]++;
    }

    ll odd = 0;
    for(ll i=0; i<N_CHARS; i++) {
        if(counters[N_CHARS] % 2 != 0)
            odd++;
    }

    return odd - 1;
}