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

    string s;
    cin >> s;

    ll digit=0;
    digit += (s[5]-'0');
    digit += (s[4]-'0')*10;
    digit += (s[3]-'0')*100;
    if(digit >= 1 && digit <= 349 && digit!=316)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}