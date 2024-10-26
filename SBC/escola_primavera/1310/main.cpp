#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, custoPorDia, Receita; 

    while(scanf("%d", &n)!=EOF) {
        cin >> custoPorDia;
        vector<int> v(n, 0);

        for(int &i: v) {
            cin >> i;
            i -= custoPorDia;
        }

        
        int current_sum=0;
        int best_sum=0;
        for(int i=0; i<v.size(); i++) {
            current_sum = max(v[i], current_sum + v[i]);
            best_sum = max(current_sum, best_sum);
        }

        cout << best_sum << '\n';
    }

    return 0;
}