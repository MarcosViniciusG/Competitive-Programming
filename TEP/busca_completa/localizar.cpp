#include <bits/stdc++.h>

using namespace std;

// A única alternativa para encontrar um elemento
// em um vetor não ordenado é a busca completa 
int find(int x, vector<int> xs)
{
    for(int i=0; i<xs.size(); i++)
    {
        if(xs[i]==x) return i;
    }

    return -1;
}

int main()
{
    vector<int>xs {5, 2, 4, 10, 20, 6, 1, 32, 3, 9};
    int x = 100, y = 2;
    cout << find(x, xs) << endl;
    cout << find(y, xs) << endl;
}