#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    int it=0;
    while(N!=0)
    {
        it++;
        vector<int> v(N, 0);
        vector<int> w(N, 0);

        for(int i=0; i<N; i++) {
            cin >> w[i] >> v[i]; 
        }

        int f[T+1];
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= N; i++)
            for (int j = w[i-1]; j <= T; j++)
                f[j] = max(f[j], f[j - w[i-1]] + v[i-1]);
        
        cout << "Instancia " << it << '\n';
        cout << f[T] << "\n\n";
        cin >> N >> T;
    }
    

    return 0;
}