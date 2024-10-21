#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    long int n, sum;
    cin >> n;

    // Calcula a soma de todos os elementos da P.A usando
    // uma fórmula
    sum = (n*(n + 1)) / 2;

    // Se a soma não for par, então não é possível achar
    // 2 subconjuntos que somem para o mesmo valor 
    if(sum%2!=0)
    {
        cout << "NO\n";
    }
    
    // Caso contrário, é possível achar e esta parte
    // cuida disso
    else
    {
        cout << "YES\n";

        // Usa um conjunto não ordenado para armazenar o primeiro
        // subconjunto de números que somam para a metade da soma do conjunto
        unordered_set<long int> subset;
        long int subset_sum = 0;
        for(long int i=n; i>0; i--)
        {
            if(subset_sum + i <= sum / 2)
            {
                subset.insert(i);
                subset_sum += i;
            }
        }

        cout << subset.size() << '\n';

        // Imprime os números do primeiro subconjunto encontrado previamente
        for(auto x : subset)
        {
            cout << x << " ";
        }

        cout << '\n';

        cout << n - subset.size() << '\n';

        // Imprime os números do segundo subconjunto através da 
        // diferença entre o conjunto e o primeiro subconjunto
        for(long int i=n; i>0; i--)
        {   
            auto it = subset.find(i); // A função retorna um ponteiro

            if(it==subset.end()) // Caso não exista o elemento no conjunto, o ponteiro será igual ao iterador final
            {
                cout << i << " ";
            }
        }

        cout << '\n';
    }
    return 0;
}