#include <bits/stdc++.h>

using namespace std;
int main() {
    int K, S;
    cin >> K >> S;
    
    int c=0;
    for(int X=0; X<=K; X++) {
        int R = S-X;
        for(int Y=0;R>=0 && Y<=K; Y++) {
            int Z = R-Y;
            if(Z>=0 && Z<=K && (X+Y+Z==S)) {
                c++;
            }
        }
    }

    cout << c << endl;
    return 0;
}