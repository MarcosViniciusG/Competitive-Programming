#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll d = ll(1e9 + 7);

int main() {
    ll n, m;
    cin >> n >> m;
    ll ways[n][m+2];
    memset(ways, 0, sizeof(ways));

    vector<int> x(n);
    for(int &i: x)
        cin >> i; 
    
    for(int i=0; i<n; i++) {
        bool go_next = false;

        for(int j=1; j<=m; j++) {
            // If is the first element
            if(!i) {
                // If the first element is 0
                // Then you have only 1 way for all m
                if(!x[i]) {
                    ways[i][j] = 1;
                }
                // Else if the first element is !=0
                // Then you have only 1 way when m==x[i]
                else
                    ways[i][x[i]] = 1;
            }
            
            // Else
            else {

                // Loop to get through all elements that are exactly one distance 
                for(int k=-1; k<2; k++) {

                    // If the i-th element is 0
                    if(!x[i]) {
                        ways[i][j] += ways[i-1][j+k];
                        ways[i][j] %= d;
                    }
                    // Else if the i-th element is != 0
                    else {
                        ways[i][x[i]] += ways[i-1][x[i]+k];
                        ways[i][x[i]] %= d;
                        go_next = true;
                    }
                }
            }
            

            if(go_next)
                break;
        }
    }

    ll soma = 0;
    for(int j=1; j<=m; j++) {
        soma += ways[n-1][j];
        soma %= d;
    }

    cout << soma << '\n';

    return 0;
}