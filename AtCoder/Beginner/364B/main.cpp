#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, SI, SJ;
    cin >> H >> W >> SI >> SJ;
    vector<string> maze;
    string s;

    SI--;
    SJ--;

    cin.ignore(1, '\n');
    for(int i=0; i<H; i++) {
        getline(cin, s);
        maze.push_back(s);
    }
    
    string commands;
    getline(cin, commands);
    for(auto c: commands) {
        if(c=='L' && (SJ-1) >= 0  && maze[SI][SJ-1] != '#')
            SJ--;
        else if(c=='R' && (SJ+1) < W  && maze[SI][SJ+1] != '#')
            SJ++;
        else if(c=='U' && (SI-1) >= 0  && maze[SI-1][SJ] != '#')
            SI--;
        else if(c=='D' && (SI+1) < H  && maze[SI+1][SJ] != '#')
            SI++;
    }

    cout << SI+1 << " " << SJ+1 << endl;
}