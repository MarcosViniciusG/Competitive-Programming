#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

void atualizar_fila(pair<ll, queue<vll>>& caixa, vll& pessoa, ll& count)
{
    if (caixa.second.size()==0)
    {
        pessoa[2] = 0;
        caixa.first = pessoa[1];
        caixa.second.push(pessoa);
        return;
    }

    ll tempo_atualizado = (caixa.second.front()[0] - pessoa[0]) + caixa.second.front()[1] + caixa.second.front()[2];
    ll tempo_de_espera = caixa.first - pessoa[0]; 
    if (tempo_de_espera < 0) tempo_de_espera = 0;
    pessoa[2] = tempo_de_espera;
    caixa.first = tempo_de_espera + pessoa[0];
    caixa.first += pessoa[1];
    while(tempo_atualizado < 0 && caixa.second.size()!=0)
    {

        tempo_atualizado += caixa.second.front()[1];
        caixa.second.pop();
    }

    if (tempo_de_espera > 20)
    {
        //cout << "Excedeu\n";
        count++;
    }

    caixa.second.push(pessoa);
}

void imprimir_fila(pair<ll, queue<vll>> caixa)
{
    while(caixa.second.size()!=0)
    {
        cout << "Tempo de chegada: " << caixa.second.front()[0] << " Tempo de atendimento: " << caixa.second.front()[1] << " Tempo de espera: " << caixa.second.front()[2] << endl;
        caixa.second.pop();
    }
}

int main()
{
    ll C, N, T, D, i, count=0;
    cin >> C >> N;

    priority_queue<pair<ll, queue<vll>>, vector<pair<ll, queue<vll>>>, greater<pair<ll, queue<vll>>>> caixas;
    for(i=0; i<C; i++)
    {
        queue<vll> fila;
        pair<ll, queue<vll>> caixa = {0, fila};
        caixas.push(caixa);
    }
    
    for(i=0; i<N; i++)
    {
        cin >> T >> D;
        vll pessoa = {T, D, 0};
        auto caixa = caixas.top();
        caixas.pop();
        atualizar_fila(caixa, pessoa, count);
        //imprimir_fila(caixa);
        caixas.push(caixa);
    }

    cout << count << endl;
    return 0;
}