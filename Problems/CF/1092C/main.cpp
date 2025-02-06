#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int n;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;

    priority_queue<pair<ll, string>> pq;
    vector<string> v;
    for (int i = 0; i < (2 * n - 2); i++)
    {
        string s;
        cin >> s;

        pq.push({ll(s.length()), s});
        v.push_back(s);
    }

    string u1 = pq.top().second;
    ll len = pq.top().first;
    pq.pop();

    string u2 = pq.top().second;
    pq.pop();

    // u1 is the prefix and u2 is the suffix
    string guess1 = u1[0] + u2;
    set<ll> lens;
    vector<char> ans1;
    for(ll i=0; i<(2*n-2); i++) {
        bool is_pre=false;
        for(ll j=1; j<=n; j++) {
            if(v[i]==guess1.substr(0, j))
                is_pre = true;
        }

        bool already=false;
        if(is_pre && lens.find(ll(v[i].length())) == lens.end()) {
            ans1.push_back('P');
            lens.insert(ll(v[i].length()));
            already=true;
        }

        bool is_suf=false;
        for(ll j=n-1; j>0; j--) {
            if(v[i]==guess1.substr(j, n-j))
                is_suf = true;
        }

        if((is_suf && !is_pre) || (is_suf && is_pre && !already)) {
            ans1.push_back('S');
        }
    }

    string guess2 = u2[0] + u1;
    lens.clear();
    vector<char> ans2;
    for(ll i=0; i<(2*n-2); i++) {
        bool is_pre=false;
        for(ll j=1; j<=n; j++) {
            if(v[i]==guess2.substr(0, j))
                is_pre = true;
        }

        bool already=false;
        if(is_pre && lens.find(ll(v[i].length())) == lens.end()) {
            ans2.push_back('P');
            lens.insert(ll(v[i].length()));
            already=true;
        }

        bool is_suf=false;
        for(ll j=n-1; j>0; j--) {
            if(v[i]==guess2.substr(j, n-j))
                is_suf = true;
        }

        if((is_suf && !is_pre) || (is_suf && is_pre && !already)) {
            ans2.push_back('S');
        }
    }

    if(ll(ans1.size())==(2*n - 2)) {
        for(auto e: ans1)
            cout << e;
    }
    else {
        for(auto e: ans2)
            cout << e;
    }

    cout << '\n';

    return 0;
}