#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    int Ai;
    vector<pair<int, char>> C;
    for(int i=0; i<N; i++) {
        cin >> Ai;
        C.push_back(make_pair(Ai, 'A'));
    }

    for(int i=0; i<M; i++) {
        cin >> Ai;
        C.push_back(make_pair(Ai, 'B'));
    }

    sort(C.begin(), C.end());

    bool one = false;
    bool can = false;

    for(auto p: C) {
        if(p.second=='A' && (!one))
            one = true;
        else if (p.second=='A' && one)
            can = true;
        else if(p.second=='B')
            one = false;
    }

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}