#include <iostream>

int main() 
{
    unsigned long int n, x, current, previous, movs=0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        if(i!=0) previous = current; // Se não for o primeiro elemento, segura o antigo elemento da array 
        std::cin >> current;

        if(i!=0 && current < previous)
        {
            // Enquanto o elemento atual for menor que o elemento prévio, some 1 ao elemento atual e 
            // atualize o número de movimentos que foram necessários
            while(current < previous)
            {
                current++;
                movs++;
            }
        }
    }
    std::cout << movs << '\n';
    return 0;
}