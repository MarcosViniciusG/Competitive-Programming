#include <bits/stdc++.h>
using namespace std;

#define dedinhos cin.tie(0)->sync_with_stdio(0)
using ll = long long;
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for(ll i = (a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (a); i >= (ll)(b); --i)
#define eb emplace_back

// just verify normally and when you find a wrong
// closing, replace it. If there is no opening, it's impossible

signed main() {
    dedinhos;
    string s;
    cin >> s;

    stack<char> q;
    int ans=0;
    bool ok = true;
    map<char, char> mp;
    mp['{'] = '}';
    mp['('] = ')';
    mp['['] = ']';
    mp['<'] = '>';
    for(auto c: s) {
        if(c=='{' || c=='(' || c=='[' || c=='<') {
            q.push(c);
        }
        else {
            if(q.empty()) {
                ok = false;
                break;
            }

            if(mp[q.top()] == c) {
                q.pop();
            }
            else {
                q.pop();
                ans++;
            }
        }
    }

    if(ok && q.size()==0)
        cout << ans << '\n';
    else
        cout << "Impossible\n";

    return 0;
}