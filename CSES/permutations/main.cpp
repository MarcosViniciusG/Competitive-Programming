#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    long int n;
    std::cin >> n;
    bool found{true};
    if(n==2 || n==3) found=false;

    for (long int i = 1; i <= n && found; i++)
    {   
        if (i % 2==0) std::cout << i << ' ';
    }

    for (long int i = 1; i <= n && found; i++)
    {
        if (i % 2!=0) std::cout << i << ' ';
    }
    
    if (!found) std::cout << "NO SOLUTION\n";
    else std::cout << '\n';
}