#include <bits/stdc++.h>

using namespace std;

int main() {
    string N;
    getline(cin, N);

    while (N.length() < 4)
    {
        N.insert(N.begin(), '0');
    }
    
    cout << N << endl;

    return 0;
}