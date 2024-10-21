#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int parent[MAXN];

int find(int value)
{
    if(parent[value]==value)
        return value;

    // O(n)
    // return find(parent[value]);

    // O(log n)
    return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
    i = find(i); j = find(j);

    if(i!=j)
        parent[i] = j;
}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i=0; i<n; i++)
        parent[i] = i;

    for(int i=0; i<q; i++)
    {
        int type, a, b;

        cin >> type >> a >> b;

        if(type==1)
            merge(a, b);
        else
        {
            if(find(a)==find(b))
                cout << "Mesmo conjunto\n";
            else
                cout << "Conjuntos diferentes\n";
        }
    }
    return 0;
}