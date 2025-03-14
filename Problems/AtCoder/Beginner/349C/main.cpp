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
    string S, T;
    cin >> S >> T;

    queue<char> q;
    for(auto c: T) {
        q.push(tolower(c));
    }

    for(auto c: S) {
        if(!q.empty()) {
            if(q.front()==c)
                q.pop();

            if(q.front()=='x' && q.size()==1)
                q.pop();
        }
        else
            break;

    }

    cout << (q.empty() ? "Yes" : "No") << '\n';

    return 0;
}