#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> hist1 (26, 0);
    vector<int> hist2(26, 0);

    for(auto c: s)
        hist1[c-'a']++;

    for(auto c: t)
        hist2[c-'a']++;

    if(hist1!=hist2) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> moves; 
    for(int i=0; i<n; i++) {
        if(s[i]!=t[i]) {
            int j;
            for(j=i+1; j<n; j++) {
                if(s[j]==t[i])
                    break;
            }

            for(j=j; j!=i; j--) {
                swap(s[j], s[j-1]);
                moves.push_back(j);
            }

        }

    }

    cout << moves.size() << '\n';
    for(auto e: moves)
        cout << e << ' ';
    cout << '\n';    

    return 0;
}