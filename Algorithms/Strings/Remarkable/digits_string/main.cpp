#include <bits/stdc++.h>

using namespace std;

string build(int n) {
    string ans="";
    for(int i=0; i<=n; i++) 
        ans += to_string(i);
    return ans;
}


int main() {
    int n;
    cin >> n;
    cout << build(n) << '\n';
    return 0;
}