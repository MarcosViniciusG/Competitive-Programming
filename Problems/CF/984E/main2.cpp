#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

// For any non-negative integers, a≤a|b , where | 
// is the bitwise “or” operation.

// OR only increases or remain the positive number unchanged

// Binary Search

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;
    ll countries[n][k];
    for(int i=0; i<n; i++)
    for(int j=0; j<k; j++)
        cin >> countries[i][j];
    
    for(int j=0; j<k; j++)
    for(int i=1; i<n; i++) {
        ll result = (countries[i][j] | countries[i-1][j]);
        countries[i][j] = result;
    }

    ll r, c, m;
    char o; 

    for(int z=0; z<q; z++) {
        cin >> m;
        ll left_pos = 0, right_pos = n - 1;

        for(int w=0; w<m; w++) {
            cin >> r >> o >> c;
            r--;

            // For each query w, do a binary search for a country that is suitable
            if(o=='<') {
                ll ri=n;
                ll li=-1;
                while(li + 1 != ri) {
                    ll mid=(ri+li)/2;
                    if(countries[mid][r] < c)
                        li = mid;
                    else
                        ri = mid;
                }
                if (li < right_pos) 
                    right_pos = li;
            }
            else if(o=='>') {
                ll ri=n;
                ll li=-1;
                while(li + 1 != ri) {
                    ll mid=(ri+li)/2;
                    if(countries[mid][r] <= c)
                        li = mid;
                    else
                        ri = mid;
                }
                if (ri > left_pos) 
                    left_pos = ri;
            }
        }

        if (left_pos <= right_pos) 
            cout << left_pos + 1 << '\n';
		else 
            cout << "-1\n";
    }
        

    return 0;
}