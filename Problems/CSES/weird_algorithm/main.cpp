#include <iostream>

int main() {
    // Long int foi usado em porquê N poderia assumir valores até 10^6
    long int n;
    std::cin >> n;
    while (n != 1)
    {
        std::cout << n << " ";
        if(n%2==0) n /= 2;      // Verifica se n é par 
        else n = (n * 3) + 1;   // Se não, segue as instruções para números ímpares  
    }

    std::cout << n << std::endl;    // Foi usado endl, mas '\n' é mais rápido
    return 0;

    // OBS: outra maneira de verificar se `n` é par é verificando
    // por bits `(n & 1) == 0`, isto funciona pois o bit menos significativo
    // de um número par é sempre 0 (apenas para números positivos)
}