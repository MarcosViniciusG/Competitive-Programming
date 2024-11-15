#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin.ignore(1, '\n');
    getline(cin, s);

    ll no=0;
    ll count=0;

    for(ll i=0; i<n; i++) {
        if(s[i]=='O')
            count++;
        else
            count = 0;
        
        if(count==k) {
            no++;
            count = 0;
        }
    }
    cout << no << '\n';

    return 0;
}