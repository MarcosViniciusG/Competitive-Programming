#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    int n, soma = 0;
    cin >> n;

    vector<int> xs(n);
    for (int& x : xs) {
        cin >> x;
        soma += x;
    }

    if (soma & 1) {
        cout << "-1\n";
        return 0;
    }
    int metade = soma / 2;

    map<int, int> somas;
    somas.emplace(0, 0);

    for (int x : xs) {
        stack<pair<int, int>> inserir;
        for (auto [valor, anterior] : somas) {
            if (valor + x > metade) break;
            inserir.emplace(valor + x, x);
        }

        while (!inserir.empty()) {
            auto [s, y] = inserir.top();
            if (somas.find(s) == somas.end())
                somas[s] = y;
            inserir.pop();
        }
    }

    multiset<int> alice(all(xs)), bob;
    int s_alice = 0, s_bob = 0;

    soma = metade;
    if (!found(soma, somas)) {
        cout << -1 << '\n';
        return 0;
    }

    int at = somas[soma];
    while (at != 0) {
        bob.emplace(at);
        alice.erase(alice.find(at));
        soma -= at;
        at = somas[soma];
    }

    for (int i = 0; i < n; ++i) {
        if (s_alice < s_bob) {
            auto it = alice.begin();
            s_alice += *it;
            cout << *it << (i == n - 1 ? '\n' : ' ');
            alice.erase(it);
        }
        else {
            auto it = bob.begin();
            s_bob += *it;
            cout << *it << (i == n - 1 ? '\n' : ' ');
            bob.erase(it);
        }
    }
}
