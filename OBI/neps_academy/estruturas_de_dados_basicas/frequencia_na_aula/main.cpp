#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll N, V, i;
    cin >> N;
    map<ll, int> alunos;

    for(i=0; i<N; i++)
    {
        cin >> V;
        alunos[V] = 1;
    }

    cout << alunos.size() << endl;
}