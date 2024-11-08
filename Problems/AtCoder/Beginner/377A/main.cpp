#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    string s;
    getline(cin, s);

    bool al[3] = {0};
    for(auto c: s) {
        if(c=='A')
            al[0] = true;
        else if(c=='B')
            al[1] = true;
        else if(c=='C')
            al[2] = true;
    }

    if(al[0] && al[1] && al[2])
        cout << "Yes\n";
    else
        cout << "No\n";


    return 0;
}