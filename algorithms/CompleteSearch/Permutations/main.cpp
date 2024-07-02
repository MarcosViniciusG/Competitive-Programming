#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n_permutations(vector<int> a)
{
    sort(a.begin(), a.end());
    ll counter = 0;
    do
    {
        counter++;
    } while (next_permutation(a.begin(), a.end()));
}