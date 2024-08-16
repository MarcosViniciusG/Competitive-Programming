#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, T;
    cin >> A >> B >> T;

    int total=0;
    for(int i=A; i<=T; i+= A) {
        total += B;
    }

    cout << total << endl;
}