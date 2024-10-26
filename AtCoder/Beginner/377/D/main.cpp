#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    ll N, M, li, ri;
    cin >> N >> M;

    vector<vll> v (M+1);
    for(int i=0; i<N; i++) {
        cin >> li >> ri;
        v[li].push_back(ri);
    }

    for(int i=1; i<=M; i++) {
        sort(v[i].begin(), v[i].end());
    }

    int i=1;
    int soma=0;
    while (i <= M)
    {
        if(v[i].size()==0) {
            i++;
            continue;
        }
        int prev_i = i;

        int npos = v[i][0] - i+1; 
        int total= (npos*npos) - 1;

        int new_i=i+1;
        for(int j=i+1; j<=M; j++) {
            if(!v[j].empty() && v[j][0] < v[i][0]) {
                int jpos = v[j][0] - j+1;
                total -= (jpos*jpos);
                new_i = max(new_i, j);
            }
        }     
        if(i==prev_i)
            i++;
        else
            i = new_i;
        soma += total;
    }
    cout << soma << '\n';
    return 0;
}