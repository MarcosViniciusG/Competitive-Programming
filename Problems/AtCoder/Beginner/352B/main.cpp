#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

signed main() {
    fastio;
    string s, t;
    cin >> s >> t;

    queue<char> q;
    for(auto c: s)
        q.push(c);
    
    vll ans;
    ll i=1;
    for(auto c: t) {
        if(!q.empty()) {
            if(q.front()==c) {
                q.pop();
                ans.push_back(i);
            }
        }
        i++;
    }

    for(auto idx: ans) 
        cout << idx << ' ';
    cout << '\n';

    return 0;
}