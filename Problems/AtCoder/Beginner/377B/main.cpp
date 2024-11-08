#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    vector<bool> rows(8, false);
    vector<bool> columns(8, false);

    char c;

    int freerows=0;
    int freecolumns=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> c;
            if(c=='#') {
                rows[i] = true;
                columns[j] = true;
            }
        }
        cin.ignore(1, '\n');
    }

    // for(auto e: rows)
    //     cout << e << " ";
    
    // cout << '\n';


    // for(auto e: columns)
    //     cout << e << " ";

    // cout << '\n';

    int r=0;
    int co=0;
    for(int i=0; i<8; i++) {
        if(!rows[i])
            r++;
        if(!columns[i])
            co++;
    }

    cout << (r*co) << '\n';

    return 0;
}