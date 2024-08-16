// ax + by = c
// ax ≡ c (mod b)
// by ≡ c (mod a)
// Quando a e b são coprimos, a solução é x ≡ c(a^-1) (mod b)
// Caso contrário, é (a/g)x ≡ (c/g) (mod b/g)
// Ou seja x ≡ (c/g)[(a/g)^-1] mod(b/g) e y = (c-ax)/b

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    int g = gcd(a, b, x, y);

    cout << x << " " << y << endl;

    bool can = false;
    if(x>=0 && y>=0)
        can = true;
    else if(x < 0 && y>=0) {
        int k = floor(g*x / b);
        int x1 = (x-k*b/g);
        int y1 = (y+k*a/g); 
        if(x1 >= 0 && y1>= 0)
            can = true;
    }
    else if(x >= 0 && y<0) {
        int k = ceil(-g*y/a);
        int x1 = (x-k*b/g);
        int y1 = (y+k*a/g);
    
        if(x1 >= 0 && y1>= 0) 
            can = true;
    }
    
    if(c % g==0 && can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}