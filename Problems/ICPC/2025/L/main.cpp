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

    vector<string> words;
    map<string, pll> mp;
    vector<pll> xs;
    string s;
    ll x, y;
    rep(i, 0, n) {
        cin >> s;
        cin >> x >> y;
        mp[s] = {x, y};
        words.push_back(s);
        xs.push_back({x, y});
    }

    ll m;
    cin >> m;
    vector<string> text;
    rep(i, 0, m) {
        cin >> s;
        text.push_back(s);
    }

    ll q, k;
    cin >> q >> k;
    
    while(q--) {
        ll f;
        cin >> f;
        vector<string> obj(f);
        rep(i, 0, f) {
            cin >> obj[i];
        }

        vector<string> candidates;
        int ogk = k;
        while(candidates.empty() && k > 0) {
            int counter=0;
            rep(i, 0, m) {
                if(counter==k) {
                    candidates.push_back(text[i]);
                    counter=0;
                }

                if(obj[f-k+counter]==text[i])
                    counter++;
                else
                    counter=0;
            }
            k--;
        }
        k = ogk;

        for(auto e: candidates)
            cout << e << ' ';
        cout << '\n';

        for(auto e: obj)
                cout << e << ' ';

        ll best=-LLONG_MAX;
        string ans="*";
        rep(i, 0, n) {
            if(candidates.empty()) break;;
            ll score=0;
            rep(j, 0, candidates.size()) {
                pll ci = {0, 0};
                if(mp.find(candidates[j])!=mp.end())
                    ci = mp[candidates[j]];

                // inner product
                ll sm=0;
                sm += xs[i].first * ci.first + xs[i].second * ci.second;

                score += sm;
            }

            if(score > best) {
                best = score;
                ans = words[i];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}