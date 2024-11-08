#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    int soma=0;
    for(int &i: a) {
        cin >> i;
        soma += i;
    }

    int W = soma/2;

    bool f[W+1];
    memset(f, false, sizeof(f));
    f[0] = true;

    int chosen[W+1];
    memset(chosen, -1, sizeof(chosen));

    for (int k = 0; k < n; k++) {
        for (int x = W; x >= 0; x--) {
            if (f[x] && (x+a[k]) <= W) {
                f[x+a[k]] = true;
                if(chosen[x+a[k]]==-1)
                    chosen[x+a[k]] = k;
            }
        }
    }

    if((soma & 1) || !f[W]) {
        cout << -1 << "\n";
        return 0;
    }

    vector<bool> items (n, false);

    while(W > 0) {
        int i = chosen[W];
        items[i] = true;
        W -= a[i];
    }

    vector<int> alice, bob;
    for(int i=0; i<n; i++) {
        if(items[i]) {
            // cout << "Alice: " << a[i] << '\n';
            alice.push_back(a[i]);
        }
        else {
            // cout << "Bob: " << a[i] << '\n';
            bob.push_back(a[i]);
        }
    } 

    int total_alice=0, total_bob=0, j=0;
    for(int i=0; i<alice.size() || j<bob.size(); i++) {
        if(total_alice <= total_bob) {
            total_alice += alice[i];
            cout << alice[i] << " ";
        }
        else {
            total_bob+=bob[j];
            cout << bob[j] << " ";
            j++;
            i--;
        }
    }
    cout << "\n";
    

    return 0;
}