#include <iostream>

using namespace std;
int main()
{
    long long int n, result=2, i;
    cin >> n;

    // Exponenciação
    for(i=1; i<n; i++)
    {
        // Modulo para não acontecer integer overflow
        result = (result * 2) % (1000000000 + 7); 
    }

    cout << result << '\n';
    return 0;
}