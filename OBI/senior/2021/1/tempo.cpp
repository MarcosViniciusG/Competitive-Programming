#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    int X, n, offset=0;

    // Variável que registra o tempo passado (é atualizada após toda leitura)
    ll time=1;

    char c;
    string line, x;

    // Map que utiliza como chave o número do amigo e como valor o tempo que a mensagem foi recebida (int)
    map<int, ll> mp;

    // Map que verifica se há alguma mensagem pendente, chave é o número do amigo e o valor é booleano
    map<int, bool> pendente;

    // Map que guarda o tempo total de cada amigo, a chave é o número do amigo e o valor é tempo total (int)
    map<int, ll> tempos;

    // Leitura do número de casos  
    cin >> n; 
    cin.ignore(1, '\n');
  
    while(n--)
    {   
        // Leitura da linha 
        getline(cin, line);

        // Extração do tipo de registro
        c = line[0];

        // Extração do número do amigo ou tempo passado
        x="";
        for(int i=2; i<line.length(); i++)
            x+=line[i];

        // Converte string para inteiro
        X = stoi(x);

        // Se o comando for tempo, então adiciona o valor
        if(c=='T')
        {
            time += X;

            // Muda o offset para não adicionar tempo extra
            offset = 0;
        }            

        // Se o comando for de enviar, então some no tempo de resposta total a 
        // diferença entre o tempo atual e o tempo que demorou para responder 
        if(c=='E')
        {
            time += offset;
            offset = 1; 

            if(tempos.find(X) != tempos.end())
                tempos[X] += (time - mp[X]);
            else
                tempos[X] = time - mp[X];

            pendente[X] = false; 
        }
        // Se o comando for de receber, então guarde o valor do tempo em que a mensagem foi recebida
        else if (c=='R')
        {
            time += offset;
            offset = 1;
            mp[X] = time;
            pendente[X] = true;
        }
    }

    // Itera sobre os tempos totais de cada amigo
    for (auto k = tempos.begin(); k != tempos.end(); k++)
    {
        // Caso houver alguma mensagem que foi recebida, mas não foi 
        // respondida (há algum valor presente na chave do amigo),
        // então imprima -1
        if(pendente[k->first])
            cout << k->first << " " << -1 << endl;
        // Se não, imprima o número do amigo e o tempo de resposta total
        else
            cout << k->first << " " << k->second << endl;
    }

    return 0;
}