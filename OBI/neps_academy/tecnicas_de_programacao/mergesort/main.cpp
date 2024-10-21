#include <bits/stdc++.h>

using namespace std;
void merge(int l, int r, vector<int>& x)
{

    //cout << l << " " << r << endl;
    int mid = (l+r) / 2;
    int p1 = l;
    int p2 = mid+1;

    vector<int> S;

    while(p1<=mid && p2 <= r)
    {
        if(x[p1] <= x[p2])
        {
            S.push_back(x[p1]);
            p1++;
        }
        else
        {
            S.push_back(x[p2]);
            p2++;
        }
    }

    while(p1 <= mid)
    {
        S.push_back(x[p1]);
        p1++;
    }

    while(p2 <= r)
    {
        S.push_back(x[p2]);
        p2++;
    }

    for(int i=0; i<S.size(); i++)
    {
        x[l + i] = S[i];
    }
}

void mergeSort(int l, int r, vector<int>& x)
{
    int mid;
    //cout << l << " " << r << endl;

    if(l < r)
    {   
        mid = (l + r)/2;
        mergeSort(l, mid, x);
        mergeSort(mid+1, r, x);
        merge(l, r, x);
    }
}

int main()
{
    vector<int> x {9, 4, 2, 1, -3, 1, 7, 19, 32, 23, -17};
    int N = x.size();

    mergeSort(0, N-1, x);

    for(int i=0; i<N; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}