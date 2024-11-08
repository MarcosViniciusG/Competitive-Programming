#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int H[N];

    int ways=0;
    for(int i=0; i<N; i++) {
        cin >> H[i];

        bool can = true;

        for(int j=i-1; j>=0; j--) {
            if(H[i] < H[j])
                can = false;
        }

        ways += (can==true);
    }

    cout << ways << endl;


    return 0;
}