#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    int n;
    string s;

    cin >> n;
    cin.ignore(1, '\n');
    getline(cin, s);

    bool is_odd = (n & 1);
    bool bar = (s[(n+1)/2 - 1]=='/');
    bool one=true, two=true;

    for(int i=0; i<(n+1)/2-1; i++) {
        if(s[i]!='1')
            one = false;
    }

    for(int i=(n+1)/2; i<n; i++) {
        if(s[i]!='2')
            two = false;
    }

    if(is_odd && bar && one && two)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}