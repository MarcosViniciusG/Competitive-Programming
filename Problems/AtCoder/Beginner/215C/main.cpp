#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    int n;
    cin >> s >> n;

    int counter=0;
    sort(s.begin(), s.end());
    do
    {
        counter++;
        if(counter==n) 
            break;
        
    } while (next_permutation(s.begin(), s.end()));
    
    cout << s << '\n';

    return 0;
}