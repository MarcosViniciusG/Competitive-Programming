#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, ai, s;
    vector<ll> a;
    cin >> n >> s;

    set<ll> prefixes;
    ll soma=0;
    prefixes.insert(soma);
    for(ll i=0; i<n; i++) {
        cin >> ai;
        a.push_back(ai);
        soma += ai;
        prefixes.insert(soma);
    }

    set<ll> suffix;
    soma = 0;
    suffix.insert(soma);
    for(ll i=n-1; i>=0; i--) {
        soma += a[i];
        suffix.insert(soma);
    }
    

    ll target = s % soma;

    // cout << target << '\n';
    // cout << "PREFIXES: \n";
    // auto it = prefixes.begin();
    // while(it!= prefixes.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << "\n\n";
    // cout << "SUFFIXES: \n";
    // it = suffix.begin();
    // while(it!= suffix.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << "\n\n";

    bool can=false;
    auto it = prefixes.begin();
    while(it!= prefixes.end()) {  
        ll newt = target - (*it);
        if(newt < 0)
            break;

        if(suffix.find(newt)!=suffix.end())
            can = true;

        it++;
    }
    it = suffix.begin();
    while(it!= suffix.end()) {  
        ll newt = target - (*it);
        if(newt < 0)
            break;

        if(prefixes.find(newt)!=prefixes.end())
            can = true;

        it++;
    }
    
    if(!can) {
        ll q = s / soma;
        q--;
        if(q > -1) {
            target = s - (q*soma);
            it = prefixes.begin();
    while(it!= prefixes.end()) {  
        ll newt = target - (*it);
        if(newt < 0)
            break;

        if(suffix.find(newt)!=suffix.end())
            can = true;

        it++;
    }

    it = suffix.begin();
    while(it!= suffix.end()) {  
        ll newt = target - (*it);
        if(newt < 0)
            break;

        if(prefixes.find(newt)!=prefixes.end())
            can = true;

        it++;
    }
        }

    }

    cout << (can ? "Yes" : "No") << '\n';
 
    return 0;
}