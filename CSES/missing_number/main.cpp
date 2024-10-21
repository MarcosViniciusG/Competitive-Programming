#include <iostream>
#include <vector>

int main() 
{
    long int n;
    int i, input;
    std::cin >> n;
    std::vector<int> nums(n, 0);  // Inicializa um vetor de tamanho n com 0
    for(i=0; i<n-1; i++)
    {
        std::cin >> input;
        nums[input-1] = 1;  // Usa o input como índice (-1 pois vetores começam com 0) 
    }

    for(i=1; i<=n && nums[i-1]!=0; i++);

    std::cout << i << '\n'; 
    return 0;
}