#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<char, int> mp;
    mp.insert({'a', 1});
    mp.insert({'b', 2});
    mp.insert({'c', 3});
    
    auto ptr = mp.begin();
    cout << "Primeira Chave: " << ptr->first << " Primeiro Elemento: " << ptr->second << endl;

    ptr = mp.end();
    ptr--;
    cout << "Última Chave: " << ptr->first << " Último Elemento: " << ptr->second << endl;

    cout << "Número de elementos: " << mp.size() << endl;

    if (mp.find('c') != mp.end())
        cout << "Chave existe\n";
    else
        cout << "Chave não existe\n";

    mp.erase('c');

    if (mp.find('c') != mp.end())
        cout << "Chave existe\n";
    else
        cout << "Chave não existe\n";

    cout << "Acesso direto: " << mp['b'] << endl;

    mp.clear();

    cout << "Número de elementos: " << mp.size() << endl;

    return 0;
}