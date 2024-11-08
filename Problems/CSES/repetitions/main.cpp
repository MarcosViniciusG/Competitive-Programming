#include <iostream>
#include <string>

int main() 
{   
    // Cria uma string. Strings da lib são de tamanhos dinâmicos
    std::string sequence{};
    std::cin >> sequence;

    int frequency=1, longest=1;
    for(int i=1; sequence[i]!='\0'; i++) 
    {
        if(sequence[i-1]==sequence[i]) 
        {
            frequency++;
            if (frequency>longest) longest=frequency;
        }
        else frequency=1;
    }

    std::cout << longest << '\n';
    return 0;
}