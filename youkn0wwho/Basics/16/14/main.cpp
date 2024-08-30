#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> w;
vector<int> v;

int N, W;
ll mx=0;

void solve(int n, vector<int> chosen, ll sw, ll sv) {
    if(sw>W)
        return;

    if(n==N) {
        //cout << sw << " " << sv << endl;
        mx = max(mx, sv);
    }
    else {
        for(int i=0; i<N; i++) {
            if(chosen[i]==1)
                continue;
        
            chosen[i] = 1;
            solve(n+1, chosen, sw+w[i], sv+v[i]);
            
            solve(n+1, chosen, sw, sv);
        }
    }
}

int main() {
    cin >> N >> W;

    int wi, vi;

    for(int i=0; i<N; i++) {
        cin >> wi >> vi;
        w.push_back(wi);
        v.push_back(vi);
    }

    vector<int> chosen (N, 0);
    solve(0, chosen, 0, 0);

    cout << mx << endl;
    return 0;
}