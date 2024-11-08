#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll N, M;
    cin >> N >> M;
    cin.ignore(1, '\n');

    string Si;
    vector<string> S;

    vll order;

    for(ll i=0; i<N; i++) {
        getline(cin, Si);
        S.push_back(Si);
        order.push_back(i);
    }

    ll min_visited=30;

    do
    {
        ll visited=0;
        ll sum=0;
        ll marked[M] = {0};

        for(auto i: order) {
            visited++;
            for(ll j=0; j<S[i].length(); j++) {
                if(S[i][j]=='o' && marked[j]==0) {
                    marked[j]=1;
                    sum++;
                }

                if(sum==M)
                    break;
            }

            if(sum==M)
                break;
        }

        min_visited = min(min_visited, visited);
    } while (next_permutation(order.begin(), order.end()));
    
    cout << min_visited << endl;
    return 0;
}