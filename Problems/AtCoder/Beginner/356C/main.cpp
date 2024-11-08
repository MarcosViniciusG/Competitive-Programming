#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> ps;
    vector<vector<int>> fs;


    int Ci, Ai;
    char Ri;

    int psl = 0;
    int fsl = 0;

    for(int i=0; i<M; i++) {
        cin >> Ci;
        vector<int>A;
        for(int j=0; j<Ci; j++) {
            cin >> Ai;
            A.push_back(Ai - 1);
        }

        cin >> Ri;
        cin.ignore(1, '\n');

        if(Ri=='o') {
            ps.push_back(A);
            psl++;
        }
        else {
            fs.push_back(A);
            fsl++;
        }
    }

    ll ways=0;
    for(int bit=0; bit<(1 << N); bit++) {
        bool subset[N];

        for(int i=0; i<N; i++) {
            if(bit & (1 << i))
                subset[i] = true;
            else
                subset[i] = false;
        }

        bool can = true;

        // Iterate through passed tests
        for(int i=0; i<psl; i++) {
            int t=0;
            for(int j=0; j<ps[i].size(); j++) {
                if(subset[ps[i][j]])
                    t++;
            }

            if(t < K)
                can = false;
        }

        // Iterate through failed tests
        for(int i=0; i<fsl; i++) {
            int t=0;
            for(int j=0; j<fs[i].size(); j++) {
                if(subset[fs[i][j]])
                    t++;
            }

            if(t >= K)
                can = false;
        }

        if (can)
            ways++;

    }

    cout << ways << endl;

    return 0;
}