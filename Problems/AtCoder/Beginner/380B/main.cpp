#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string S;
    getline(cin, S);

    vector<int> ans;
    int contador=0;
    for(int i=1; i<S.size(); i++) {
        if(S[i]!='|')
            contador++;
        else {
            ans.push_back(contador);
            contador=0;
        }
    }

    for(auto e: ans)
        cout << e << " ";
    cout << '\n';

    return 0;
}