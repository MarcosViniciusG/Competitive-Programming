#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for(int c=5; c<=n; c++)
    {
        for(int b=1; b<c; b++) {
            int a_sqr = c*c - b*b;
            int a = sqrt(a_sqr);

            if(a*a == a_sqr)
                cnt++;      
        }

    }

    cout << cnt / 2 << endl;

    return 0;
}