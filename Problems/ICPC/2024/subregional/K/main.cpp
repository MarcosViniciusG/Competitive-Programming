#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n, ai;
    cin >> n;
    vector<int> a;

    int soma=0;
    for(int i=0; i<n; i++) {
        cin >> ai;
        
        soma += ai;
        a.push_back(ai);
    }


    bool dp[n+1][soma+1];

    // É impossível formar qualquer soma != 0 com 0 elementos
    for(int i=0; i<=soma; i++) {
        dp[0][i] = false;
    }

    // Sempre é possível formar a soma 0 com qualquer número de elementos
    for(int i=0; i<=n; i++) {
        dp[i][0] = true;
    }


    // Preenchimento da tabela DP

    // O primeiro for loop vai dizer quantos   
    // itens foram incluídos [0, i) para formar a soma j
    for(int i=1; i<=n; i++) {

        // O segundo for loop vai dizer se os primeiros i items
        // são capazes de formar a soma j
        for(int j=1; j<=(soma); j++) {
            if((j-a[i-1]) < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j-a[i-1]] | dp[i-1][j]);
        }
    }
 
            // DEBUG
    // Imprime a tabela DP
    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=(soma); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if((soma%2) || !(dp[n][soma/2])) {
        cout << -1 << endl;
        return 0;
    }

    int j = soma/2;
    vector<int> alice;
    vector<int> bob;

    // Pega os elementos de forma alternada
    for(int i=n; i>0; i--) {
        if(!dp[i-1][j]) {
            alice.push_back(a[i-1]);
            j -= a[i-1];
        }
        else {
            bob.push_back(a[i-1]);
        }
    }


    int total_alice=0, total_bob=0, printados=0;
    j=0;
    for(int i=0; i<alice.size() || j<bob.size(); i++) {
        if(total_alice <= total_bob) {
            total_alice += alice[i];
            cout << alice[i] << " ";
        }
        else {
            total_bob+=bob[j];
            cout << bob[j] << " ";
            j++;
            i--;
        }
    }

    cout << '\n';

    return 0;
}