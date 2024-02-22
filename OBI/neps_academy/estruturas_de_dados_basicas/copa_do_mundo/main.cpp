#include <bits/stdc++.h>

using namespace std;
int main()
{
    char c;
    int i, M, N;
    list<char> times;
    for(c='A'; c<='P'; c++)
    {
        times.insert(times.end(), c);
    }

    auto ptr = times.begin();
    auto ptr_cp = ptr;

    for(i=0; i<15; i++)
    {
        cin >> M >> N; 
        ptr_cp++; ptr_cp++;
        if(M > N) ptr++;
        
        times.erase(ptr);

        if(ptr_cp==times.end()) ptr_cp=times.begin();

        ptr = ptr_cp;
    }

    cout << *ptr << endl;

    return 0;
}