#include <bits/stdc++.h>

using namespace std;

int main() {
    int G, P, W, E, ei, pi;
    cin >> G;
    for(int it=0; it<G; it++)
    {
        cin >> P >> W;
        
        vector<int> e(P);
        vector<int> p(P);

        for(int i=0; i<P; i++) {
            cin >> ei >> pi;
            e[i] = ei;
            p[i] = pi;
        }

        int dp[P+1][W+1];
        for(int i=0; i<W+1; i++) 
            dp[0][i] = 0;

        for(int i=1; i<=P; i++) {
            for(int j=0; j<=W; j++) {
                if(j-p[i-1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i-1]] + e[i-1]); 
            }
        }

        cout << "Galho " << it+1 << ":\n";
        cout << "Numero total de enfeites: " << dp[P][W] << "\n";
        cout << "\n";  
    }

    return 0;
}