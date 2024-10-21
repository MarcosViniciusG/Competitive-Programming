#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if(B > A)
        cout << B-A+1; 
    else
        cout << 0;

    cout << endl;


    return 0;
}