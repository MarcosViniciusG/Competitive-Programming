#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ai;
    cin >> n;
    vector<int> a;

    a.push_back(0);
    int soma=0;
    for(int i=0; i<n; i++) {
        cin >> ai;
        
        soma += ai;
        a.push_back(ai);
    }

    if(soma & 1) {
        cout << -1 << endl;
        return 0;
    }

    bool dp[n+1][soma+1];
    for(int i=0; i<soma+1; i++) {
        dp[0][i] = 0;
    }

    soma /= 2;

    for(int i=1; i<n+1; i++) {
        for(int j=0; j<soma; j++) {

        }
    }

    return 0;
}