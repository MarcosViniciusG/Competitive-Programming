#include <bits/stdc++.h>

using namespace std;

string substring(string s, int start, int n) {
    string s2="";
    for(int i=start; i<(n+start) && i<(s.length()); i++)
        s2 += s[i];

    return s2;
}

int main() {
    string s1 = "example";

    cout << substring(s1, 0, 2) << endl;

    return 0;
}