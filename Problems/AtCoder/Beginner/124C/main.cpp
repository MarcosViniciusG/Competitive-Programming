#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    getline(cin, S);

    bool alt=false;
    int q1 = 0;

    for(int i=0; i<S.length(); i++) {
        if(alt) {
            q1 += (S[i]!='0');
            alt = false;
        }
        else {
            q1 += (S[i]!='1');
            alt = true;
        }
    }

    alt = false;
    int q2 = 0;
    for(int i=0; i<S.length(); i++) {
        if(alt) {
            q2 += (S[i]!='1');
            alt = false;
        }
        else {
            q2 += (S[i]!='0');
            alt = true;
        }
    }

    cout << min(q1, q2) << endl;

    return 0;
}