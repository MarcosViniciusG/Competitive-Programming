#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int H, W, D;
char S[15][15];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W >> D;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> S[i][j];
        }
    }

    int best=2;
    for(int h1_y=0; h1_y<H; h1_y++) {
        for(int h1_x=0; h1_x<W; h1_x++) {
            if(S[h1_y][h1_x]=='#')
                continue;
            for(int h2_y=0; h2_y<H; h2_y++) {
                for(int h2_x=0; h2_x<W; h2_x++) {
                    if(S[h2_y][h2_x]=='#')
                        continue;
    
                    int humidified=0;
                    for(int i=0; i<H; i++) {
                        for(int j=0; j<W; j++) {
                            if(S[i][j]!='#') {
                                if(abs(i-h1_y) + abs(j-h1_x) <= D)
                                    humidified++;
                                else if(abs(i-h2_y) + abs(j-h2_x) <= D)
                                    humidified++;
                            }
                        }
                    }
                    best = max(best, humidified);
                }
            }
        } 
    }
           
    cout << best <<'\n';

    return 0;
}