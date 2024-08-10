#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, q, l, r;
    string a, b;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        cin.ignore(1, '\n');
        getline(cin, a);
        getline(cin, b);

        // Prefix sum (Matrix)
        int cA[n+1][26] = {0};
        int cB[n+1][26] = {0};

        for(int i=1; i<=n; i++) {
            cA[i][a[i-1] - 'a']++;

            for(int j=0; j<26; j++)
                cA[i][j] += cA[i - 1][j];
        }

        for(int i=1; i<=n; i++) {
            cB[i][b[i-1] - 'a']++;

            for(int j=0; j<26; j++)
                cB[i][j] += cB[i - 1][j];
        }

        while(q--) {
            cin >> l >> r;

            int diff=0;
            for(int i=0; i<26; i++) {
                int v1 = cA[r][i] - cA[l - 1][i];
                int v2 = cB[r][i] - cB[l - 1][i];
                    diff+=abs(v1-v2);
            }
            cout << (diff / 2) << endl;
        }

    }

}