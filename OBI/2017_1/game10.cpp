#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, D, A, movs;
    cin >> N >> D >> A;

    if(A < D) movs = D - A;
    else if(A > D) movs = (N - A) + D;
    else movs = 0;

    cout << movs << endl;
    return 0;
}