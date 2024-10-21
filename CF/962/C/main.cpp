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
        int cA[256] = {0};
        int cB[256] = {0};

        for(int i=0; i<n; i++) {
            cA[a[i]]++;
            cB[b[i]]++;
        }

        for(int i=0; i<q; i++) {
            cin >> l >> r;
            l--;
            r--;
            for(int j=0; j<l; j++) {
                cA[a[j]]--;
                cB[b[j]]--;
            }
            for(int j=n-1; j>r; j--) {
                cA[a[j]]--;
                cB[b[j]]--;
            }

            int diff=0;
            for(int j=0; j<256; j++) {
                if(cA[j] != cB[j]) diff++;
            }
            cout << (diff / 2) << endl;

            for(int j=0; j<l; j++) {
                cA[a[j]]++;
                cB[b[j]]++;
            }
            for(int j=n-1; j>r; j--) {
                cA[a[j]]++;
                cB[b[j]]++;
            }
        }

    }

}