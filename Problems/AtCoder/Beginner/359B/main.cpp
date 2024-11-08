#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int N, Ai;
    cin >> N;
    int prev_prev, prev;

    cin >> prev_prev;
    cin >> prev;

    int cou = 0;
    for(int i=2; i<N*2; i++) {
        cin >> Ai;
        // cout << prev_prev << " " << prev << " " << Ai << endl;
        if(Ai==prev_prev)
            cou ++;

        prev_prev = prev;
        prev = Ai;
    }
    cout << cou << endl;
}