#include <bits/stdc++.h>

using namespace std;

string build(int n) {
    string ans="";
    if(n==0) return ans;
    else if(n==1) return (ans+'b');
    else if(n==2) return (ans+'a');

    ans += build(n-1);
    ans += build(n-2);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << build(n) << '\n';

    return 0;
}