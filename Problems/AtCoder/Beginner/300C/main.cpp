#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w;
    cin >> h >> w;

    vector<int> s(min(h, w), 0);
    vector<string> grid;

    cin.ignore(1, '\n');
    
    string place="";
    for(int i=0; i<h; i++) {
        getline(cin, place);
        grid.push_back(place);
    }

    set<pll> explored;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            pll coords = make_pair(i, j);
            if(grid[i][j]=='#' && (explored.find(coords)==explored.end())) {
                explored.insert(coords);
                bool cross1=false;
                if((i-1 > -1) && (j-1 > -1) && grid[i-1][j-1]=='#')
                    cross1 = true;
                else if((i+1 < h) && (j+1 < w) && grid[i+1][j+1]=='#')
                    cross1 = true;
                
                int siz=0, size_1=0, size_2=0;
                if(cross1) {
                    int offset = 1;

                    // Searching upper
                    while((i-offset > -1) && (j-offset > -1) && grid[i-offset][j-offset]=='#') {
                        siz++;
                        size_1++;
                        offset++;
                        explored.insert(make_pair(i-offset, j-offset));
                    }
                    
                    offset = 1;
                    // Searching lower
                    while((i+offset < h) && (j+offset < w) && grid[i+offset][j+offset]=='#') {
                        siz++;
                        size_2++;
                        offset++;
                        explored.insert(make_pair(i+offset, j+offset));
                    }
                }
                else {
                    int offset = 1;
                    // Searching upper
                    while((i-offset > -1) && (j+offset < w) && grid[i-offset][j+offset]=='#') {
                        siz++;
                        size_1++;
                        offset++;
                        explored.insert(make_pair(i-offset, j+offset));
                    }
                    
                    offset=1;
                    // Searching lower
                    while((i+offset < h) && (j-offset > -1) && grid[i+offset][j-offset]=='#') {
                        siz++;
                        size_2++;
                        offset++;
                        explored.insert(make_pair(i+offset, j-offset));
                    }
                }
                
                int center_off = abs(size_1-size_2) / 2;
                bool upper= (size_2>size_1);

                int center_i, center_j;
                if(upper) {
                    center_i = i+center_off;
                    if(cross1)
                        center_j = j+center_off;
                    else
                        center_j = j-center_off;
                }
                else {
                    center_i = i-center_off;
                    if(cross1)
                        center_j = j-center_off;
                    else
                        center_j = j+center_off;
                }

                if(cross1) {
                    int offset = 1;
                    // Searching upper
                    while((center_i-offset > -1) && (center_j+offset < w) && grid[center_i-offset][center_j+offset]=='#') {
                        size_1++;
                        offset++;
                        explored.insert(make_pair(center_i-offset, center_j+offset));
                    }
                    
                    offset=1;
                    // Searching lower
                    while((center_i+offset < h) && (center_j-offset > -1) && grid[center_i+offset][center_j-offset]=='#') {
                        size_2++;
                        offset++;
                        explored.insert(make_pair(center_i+offset, center_j-offset));
                }
                }
                else {
                    int offset = 1;

                    // Searching upper
                    while((center_i-offset > -1) && (center_j-offset > -1) && grid[center_i-offset][center_j-offset]=='#') {
                        size_1++;
                        offset++;
                        explored.insert(make_pair(center_i-offset, center_j-offset));
                    }
                    
                    offset = 1;
                    // Searching lower
                    while((center_i+offset < h) && (center_j+offset < w) && grid[center_i+offset][center_j+offset]=='#') {
                        size_2++;
                        offset++;
                        explored.insert(make_pair(center_i+offset, center_j+offset));
                    }
                }

                s[(siz/2) - 1]++;
            } 

        }
    }

    for(auto e: s) {
        cout << (e/3) << " ";
    }
    cout << "\n";

    return 0;
}