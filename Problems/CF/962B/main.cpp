#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<string> matrix) {
    int b = n / k;
    int reduced[b][b];

    for(int i=0; i<n; i+= k) {
        for(int j=0; j<n; j+= k) {
            if(matrix[i][j]=='1')
                reduced[i/k][j/k] = 1;
            else
                reduced[i/k][j/k] = 0;
        }
    }
        
    for(int i=0; i<b; i++) {
        for(int j=0; j<b; j++) {
            cout << reduced[i][j];    
        }
        cout << endl;
    }
}

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<string> matrix;
        cin.ignore(1, '\n');
        for(int i=0; i<n; i++) {
            string s;
            getline(cin, s);
            matrix.push_back(s);
        }
        
        solve(n, k, matrix);
    }

    return 0;
}