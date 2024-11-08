#include <bits/stdc++.h>

using namespace std;

int main() {

    string s = "abc";
    int n = s.size();

    // Iterate through all subsequences of a string
    // (including empty subsequence)
    // O(2^n)
    for(int bit=0; bit < (1 << n); bit++) {
        string sub="";
        for(int i=0; i<n; i++) {
            if(bit & (1 << i))
                sub += s[i];
        }
        cout << sub << '\n'; 
    }

    return 0;
}