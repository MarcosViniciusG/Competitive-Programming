#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b % a, a);
}

int main() {
    // x and y are both periods of s
    int x, y;
    cin >> x >> y;

    
    // gcd(x, y) is also a period of s
    // if and only if x+y-gcd(x, y) <= size(s) 
    cout << gcd(x, y) << '\n';

    return 0;
}