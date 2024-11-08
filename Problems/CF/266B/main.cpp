#include <bits/stdc++.h>

using namespace std;
void swap(string &fila, int pos_i, int pos_f)
{
    int temp = fila[pos_i];
    fila[pos_i] = fila[pos_f];
    fila[pos_f] = temp;
}

int main()
{
    int n, t;
    char pessoa;
    string fila;
    cin >> n >> t;
    cin.ignore(1, '\n');
    cin >> fila;

    bool troca=true;
    for(int i=0; i<t && troca; i++)
    {
        troca = false;
        for(int j=1; j<n; j++)
        {
            if(fila[j-1] == 'B' && fila[j] == 'G') 
            {
                swap(fila, j, j-1);
                troca = true;
                j++;
            }
        }
    }
    for(auto e: fila)
    {
        cout << e;
    }

    cout << endl;
    return 0;
}