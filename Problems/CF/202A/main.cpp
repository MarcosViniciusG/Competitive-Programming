#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    int n = s.size();
    bool is = true;

    for(int i=0; i<n/2 && is; i++)
        is = s[i] == s[n-1-i];

    return is;
}

signed main() {
    string s;
    getline(cin, s);

    int n = s.size();
    string biggest;
    for(int bit=0; bit < (1 << n); bit++) {
        string ans="";
        for(int i=0; i<n; i++) {
            if((1 << i) & bit)
                ans.push_back(s[i]);
        }

        if(is_palindrome(ans) && ans > biggest) {
            biggest=ans;
        }
    }
    cout << biggest << '\n';

    return 0;
}