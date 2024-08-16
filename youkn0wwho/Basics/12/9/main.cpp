#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool can = false;
    for(int i=0; i*a<= c; i++)
        for(int j=0; j*b <= c; j++)
            if(i*a + j*b == c)
                can = true;

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}