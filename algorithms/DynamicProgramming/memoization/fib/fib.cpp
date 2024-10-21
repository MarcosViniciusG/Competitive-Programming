#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    if(n==1 || n==2)
        return 1;
    else return fib(n-1) + fib(n-2);
}

int main() {
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
}