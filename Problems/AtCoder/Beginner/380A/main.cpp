#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string N;
    getline(cin, N);

    int counters[3] = {0};
    for(auto d: N) {
        if(d=='1' || d=='2' || d=='3')
            counters[d-'0'-1]++;
    }

    if(counters[0]==1 && counters[1]==2 && counters[2]==3)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}