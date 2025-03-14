#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

ll grid[3][3];

// Returns 'N' if the game isn't over
char winner(vector<vector<char>> game, ll scorer, ll scoreb) {
    ll win='N';
    
    // Every col has the same color in row i
    for(ll i=0; i<3 && win=='N'; i++) {
        if(game[i][0] != 'W' && game[i][0]==game[i][1] && game[i][0]==game[i][2])
            win = game[i][0];
    }

    // Every row has the same color in col j
    for(ll j=0; j<3 && win=='N'; j++) {
        if(game[0][j] != 'W' && game[0][j]==game[1][j] && game[0][j]==game[2][j])
            win = game[0][j];
    }

    // The first diagonal has the same color
    if(win=='N' && game[0][0]!='W' && game[0][0]==game[1][1] && game[0][0]==game[2][2])
        win = game[0][0];
    
    // The second diagonal has the same color
    if(win=='N' && game[0][2]!='W' && game[0][2]==game[1][1] && game[0][2]==game[2][0])
        win = game[0][2];
    
    // If all cells are already filled
    bool filled = true;
    for(ll i=0; i<3 && win=='N'; i++) {
        for(ll j=0; j<3 && win=='N'; j++) {
            if(game[i][j]=='W')
                filled = false;
        }
    }

    if(win=='N' && filled) {
        if(scorer>scoreb)
            win = 'R';
        else
            win = 'B';
    }

    return win;
}

char backtrack(vector<vector<char>> game, bool r, ll scorer, ll scoreb) {
    char win = winner(game, scorer, scoreb);
    if(win!='N')
        return win;

    for(int k=0; k<3; k++) {
        for(int w=0; w<3; w++) {
            // Always take the board where the current player
            // is the winner
            if(game[k][w]=='W') {
                if(r) {
                    game[k][w]='R';
                    if(win!='R')
                        win = backtrack(game, !r, scorer+grid[k][w], scoreb);
                }
                else {
                    game[k][w]='B';
                    if(win!='B')
                        win = backtrack(game, !r, scorer, scoreb+grid[k][w]);
                }
                
                game[k][w] = 'W';
            }
        }
    }

    return win;
}

signed main() {
    fastio;
    vector<vector<char>> game(3, vector<char>(3));
    for(ll i=0; i<3; i++)
    for(ll j=0; j<3; j++) {
        cin >> grid[i][j];
        game[i][j] = 'W';
    }

    char win = backtrack(game, true, 0, 0);
    if(win=='R')
        cout << "Takahashi\n";
    else
        cout << "Aoki\n";

    return 0;
}