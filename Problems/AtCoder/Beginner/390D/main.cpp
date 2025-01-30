#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

set<ll> values;
ll N;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    vll A;
    ll ai;

    for (ll i = 0; i < N; i++) {
        cin >> ai;
        A.push_back(ai);
    }

    sort(A.begin(), A.end());

    do
    {
        ll prefixes[N+1];
        prefixes[0] = 0;
        for(ll i=0; i<N; i++) {
            prefixes[i+1] = prefixes[i-1] + A[i];
        }

        for (ll bit = 0; bit < (1 << N); bit++)
        {
            vll somas;
            ll soma = 0;
            for (ll i = 0; i < N; i++)
            {
                soma += A[i];
                if (bit & (1 << i))
                {
                    somas.push_back(soma);
                    soma = 0;
                }
                else
                {
                    somas.push_back(0);
                }
            }

            ll result = soma;
            if (!result)
            {
                result = somas[0];
                for (ll i = 1; i < N; i++)
                {
                    result = result ^ somas[i];
                }
            }
            else
            {
                for (ll i = 0; i<N; i++)
                {   
                    result = result ^ somas[i];
                }
            }

            values.insert(result);
        }
    } while (next_permutation(A.begin(), A.end()));

    cout << values.size() << '\n';
    return 0;
}