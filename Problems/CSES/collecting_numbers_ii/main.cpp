#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    bool inv[n];
    memset(inv, false, sizeof(inv));
    int qnt=1;
    int mp[n+1];
    vector<int> xs;
    int xi;
    for(int i=0; i<n; i++) {
        cin >> xi;
        mp[xi] = i;
        xs.push_back(xi);
    }

    for(int i=1; i<n; i++) {
        if(mp[i+1] < mp[i]) {
            inv[i] = true;
            qnt++;
        }
    }
    

    int a, b;
    while(m--) {
        cin >> a >> b;

        int elea = xs[a-1];
        int eleb = xs[b-1];

        mp[elea] = b-1;
        mp[eleb] = a-1;
        swap(xs[a-1], xs[b-1]);

        if(elea != n) {
            bool inva = inv[elea];
            if(inva && mp[elea+1] > mp[elea]) {
                inv[elea] = false;
                qnt--;
            }
            else if(!inva && mp[elea+1] < mp[elea]) {
                inv[elea] = true;
                qnt++;
            }
        } 

        if(eleb != n) {
            bool invb = inv[eleb];
            if(invb && mp[eleb+1] > mp[eleb]) {
                inv[eleb] = false;
                qnt--;
            }
            else if(!invb && mp[eleb+1] < mp[eleb]) {
                inv[eleb] = true;
                qnt++;
            }
        }

        if(elea != 1) {
            bool inva = inv[elea-1];
            if(inva && mp[elea-1] < mp[elea]) {
                inv[elea-1] = false;
                qnt--;
            }
            else if(!inva && mp[elea-1] > mp[elea]) {
                inv[elea-1] = true;
                qnt++;
            }
        }

        if(eleb != 1) {
            bool invb = inv[eleb-1];
            if(invb && mp[eleb-1] < mp[eleb]) {
                inv[eleb-1] = false;
                qnt--;
            }
            else if(!invb && mp[eleb-1] > mp[eleb]) {
                inv[eleb-1] = true;
                qnt++;
            }
        }

        cout << qnt << '\n';
    }

    return 0;
}