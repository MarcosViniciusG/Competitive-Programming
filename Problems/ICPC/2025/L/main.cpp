#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;
#define dedinhos cin.tie(nullptr)->sync_with_stdio(false)
#define rep(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define per(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define all(xs) xs.begin(), xs.end()

signed main() {
    dedinhos;
    ll n;
    cin >> n;
    vector<string> words(n);
    map<string, pll> mp;
    ll x, y;
    rep(i, 0, n) {
        cin >> words[i];
        cin >> x >> y;
        mp[words[i]] = {x, y};
    }

    ll m;
    cin >> m;
    vector<string> text(m);
    rep(i, 0, m) 
        cin >> text[i];

    ll q, k;
    cin >> q >> k;
    
    while(q--) {
        ll f;
        cin >> f;
        vector<string> obj(f);
        rep(i, 0, f) 
            cin >> obj[i];

        vector<string> candidates;
        per(j, k, 1) {
            ll l = 0;
            rep(r, j, m) {
                ll w=l;
                for(ll c=0; w<r && obj[f-j+c]==text[w]; w++, c++);
                if(w==r)
                    candidates.push_back(text[w]);
                l++;
            }

            if(!candidates.empty())
                break;
        }

        for(auto e: obj)
            cout << e << ' ';

        if(candidates.empty()) {
            cout << "*\n";
            continue;
        }

        ll best=0;
        ll idx=0;
        rep(i, 0, n) {
            ll score=0;
            rep(j, 0, candidates.size()) {
                pll ci = {0, 0};
                if(mp.find(candidates[j])!=mp.end())
                    ci = mp[candidates[j]];

                // inner product
                score += mp[words[i]].first * ci.first + mp[words[i]].second * ci.second;
            }

            if(!i || score > best) {
                best = score;
                idx = i;
            }
        }
        candidates.clear();
        cout << words[idx] << '\n';
    }

    return 0;
}