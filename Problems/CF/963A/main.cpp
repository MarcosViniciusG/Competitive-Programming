#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;
        string s;

        cin.ignore(1, '\n');
        getline(cin, s);
        int cs[4] = {0};

        for(int i=0; i<s.length(); i++) {
            if(s[i]!= '?')
                cs[s[i] - 'A']++;
        }
        
        int maximum = 0;

        for(int i=0; i<4; i++)
            maximum += min(n, cs[i]);

        cout << maximum  << endl;
    }   


    return 0;
}