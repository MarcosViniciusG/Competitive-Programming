#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin.ignore(1, '\n');
        vector<string> carpet(n);
        for(string &i: carpet)
            getline(cin, i);

        int counterr=0;
        for(int i=0, j=0; i<n && j<m; i++, j++) {
            int last_row = (n-i);
            int last_column = (m-j);
            if((last_row <= i) || (last_column<=j)) 
                break;

            vector<char> strip;

            // All elements from first line
            for(int k=j; k<last_column; k++)
                strip.push_back(carpet[i][k]);
                
            // All elements from last column
            for(int k=i+1; k<last_row; k++)
                strip.push_back(carpet[k][last_column-1]);
                
            // All elements from last row
            for(int k=last_column-2; k>=j; k--)
                strip.push_back(carpet[last_row-1][k]);
                
            // All elements from first column
            for(int k=last_row-2; (k-1)>=i; k--)
                strip.push_back(carpet[k][j]);

            for(int k=0; k<strip.size(); k++) {
                if(
                (strip[k]=='1') && 
                (strip[(k+1)%(strip.size())])=='5' &&
                (strip[(k+2) %(strip.size())])=='4' &&
                (strip[(k+3)%(strip.size())])=='3'
                ) counterr++;
            } 
        }

        cout << counterr << '\n';
    }

    return 0;
}